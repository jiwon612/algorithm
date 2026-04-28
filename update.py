#!/usr/bin/env python

import os
from urllib import parse

HEADER="""# 
# 백준 & 프로그래머스 & Softeer 문제 풀이 목록

프로그래머스의 경우, 푼 문제 목록에 대한 마이그레이션이 필요합니다.

"""

def main():
    content = ""
    content += HEADER
    
    directories = []
    solveds = []

    # 탐색할 메인 카테고리 정의
    main_categories = ["백준", "프로그래머스", "Softeer"]

    for root, dirs, files in os.walk("."):
        dirs.sort()
        if root == '.':
            for dir in ('.git', '.github'):
                try:
                    dirs.remove(dir)
                except ValueError:
                    pass
            continue

        category = os.path.basename(root)
        
        if category == 'images':
            continue
        
        directory = os.path.basename(os.path.dirname(root))
        
        if directory == '.':
            continue
            
        if directory not in directories:
            # 백준, 프로그래머스, Softeer를 대분류로 처리
            if directory in main_categories:
                content += "\n## 📚 {}\n".format(directory)
            else:
                # 그 외 하위 폴더(난이도 등) 처리
                content += "\n### 🚀 {}\n".format(directory)
                content += "| 문제번호 | 링크 |\n"
                content += "| ----- | ----- |\n"
            directories.append(directory)

        for file in files:
            # .DS_Store 같은 시스템 파일 제외 (필요 시)
            if file.startswith('.'):
                continue
                
            if category not in solveds:
                # 파일 경로 인코딩 및 마크다운 행 추가
                file_path = parse.quote(os.path.join(root, file))
                content += "| {} | [링크]({}) |\n".format(category, file_path)
                solveds.append(category)
                print(f"추가된 문제: {directory} -> {category}")

    with open("README.md", "w") as fd:
        fd.write(content)
        
if __name__ == "__main__":
    main()
