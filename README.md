# data-structure
본 연구는 경희대학교 ``자료구조`` 수업에서 진행되었습니다.

## Overview
C++로 자료구조를 구현하고, 이를 활용해 PC 의 파일 탐색기와 유사한 파일 관리 시스템을 설계하고 구현한다. 이 시스템은 다수의 서브 폴더들과 사진, 음원과 같은 파일들을 관리할 수 있어야 한다. 이를 위한 다양한 자료구조를 설계하고, 파일 탐색기가 제공하는 다양한 기능들을 구현한다. 사용자의 편의를 고려한 GUI 도 제작한다.

### Data structure
- 기본 데이터 컨테이너: `Sorted Linked List`
- 자주 사용한 폴더, 최근 사용한 폴더: `Queue`

## Functions
1. 폴더 관리 기능
   - 폴더 생성, 삭제, 열기, 이름 바꾸기, 복사/붙여넣기, 복제, 속성 보기
2. 파일 관리 기능
   - 파일 생성, 삭제, 열기, 이름 바꾸기, 복사/붙여넣기, 복제, 속성 보기
3. 전체 관리 기능
   - 상위 폴더로 이동, 날짜 or 크기로 정렬, 폴더 및 파일 검색, 최근 열어본 폴더, 자주 사용한 폴더
4. 기타 부가 기능
   - 콘솔 다양한 글씨 색 지원
   - 실제 프로젝트 폴더 내 파일들과 연동
     - rename, delete시 프로젝트 폴더 내 실제 파일에도 적용
     - 파일의 실제 사이즈 로드해 파일 사이즈 설정,해당 파일 사이즈로 폴더 사이즈 업데이트
   - 프로그램 내에서 음악 재생 가능
   - 최근 열어본 폴더, 자주 사용한 폴더 목록에서 바로 원하는 폴더로 이동 가능

## Class diagram & GUI
[report](/report.pdf)
