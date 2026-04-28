#!/usr/bin/env python

import os
from urllib import parse

HEADER="""# 
# 백준 & 프로그래머스 & Softeer 문제 풀이 목록

"""

def main():
    # 1. 출력 순서 정의
    order = ["백준", "프로그래머스", "Softeer"]
    # 플랫폼별 데이터를 저장할 딕셔너리
    # 구조: { "플랫폼": { "난이도/분류": [ (문제명, 링크), ... ] } }
    data = {name: {} for name in order}

    for root, dirs, files in os.walk("."):
        dirs.sort()
        # 불필요한 폴더 제외
        if root == '.':
            for dir in ('.git', '.github', 'images'):
                if dir in dirs: dirs.remove(dir)
            continue

        # 현재 경로 분석
        parts = root.split(os.sep)
        if len(parts) < 3: # 플랫폼/난이도 구조가 아니면 스킵
            continue
            
        # parts[0]은 '.', parts[1]이 플랫폼명(백준 등), parts[2]가 난이도
        platform = parts[1]
        difficulty = parts[2]
        
        if platform not in order:
            continue

        for file in files:
            if file.startswith('.') or file.endswith('.md'): 
                continue
                
            # 문제명은 파일명에서 확장자 제거한 것 (예: "A+B.cpp" -> "A+B")
            problem_name = os.path.splitext(file)[0]
            file_path = parse.quote(os.path.join(root, file))
            
            if difficulty not in data[platform]:
                data[platform][difficulty] = []
            
            # 중복 방지를 위해 (문제명, 링크) 추가
            if (problem_name, file_path) not in data[platform][difficulty]:
                data[platform][difficulty].append((problem_name, file_path))

    # 2. README 작성
    content = HEADER
    
    for platform in order:
        if not data[platform]: continue
        
        content += f"\n## 📚 {platform}\n"
        
        # 난이도순(예: 1, 2, 3...)으로 정렬하여 출력
        for diff in sorted(data[platform].keys()):
            content += f"\n### 🚀 {diff}\n"
            content += "| 문제명 | 링크 |\n"
            content += "| :--- | :--- |\n"
            
            # 문제명 순으로 정렬
            for prob_name, link in sorted(data[platform][diff]):
                content += f"| {prob_name} | [링크]({link}) |\n"

    with open("README.md", "w") as fd:
        fd.write(content)
    
    print("성공적으로 README.md가 갱신되었습니다.")

if __name__ == "__main__":
    main()
