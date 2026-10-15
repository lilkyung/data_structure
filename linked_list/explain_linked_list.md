# Linked list

# Singly linked list

- 데이터를 저장할 때 데이터와 다음 데이터의 주소를 가리키는 포인터를 함께 저장하여 별도의 인덱스 없이 리스트를 만든 것

# Doubly linked list

- singly linked list에 전 데이터 주소를 추가하여 리스트를 만든 것이다. 삭제할 때 전 노드의 주소를 알고 있어 O(1)에 삭제할 수 있다.

# circular doubly linked list

- doubly linked list의 시작과 끝을 연결시킨 리스트

# 연산

## insert

- 원소를 삽입

## delete

- 원소를 삭제

## search

- 원소 조회

## size

- 리스트 길이 구하기

## traversal

- 순회하면서 조회

# 사용 예시

- 플레이 리스트(삽입, 삭제가 용이), 브라우저 앞으로 가기/ 뒤로 가기

# 배열과의 차이점

- 단점
    - 배열과는 달리 중간 값을 인덱스로 바로 불러올 수는 없다.
- 장점
    - 주소를 알고 있어 추가와 삭제가 간편하다.
    - C의 기본 배열과는 달리 크기 제한이 없어 리스트 안에 계속해서 넣을 수 있다.

# 문제 상황

- insert 할 때 할당한 메모리를 어디서 free 해야 하는가?
    - delete 과정에서 해당 노드를 remove라는 새로운 그릇에 담아 remove를 free한다.
- malloc으로 동적 할당 시킨 list *p는 여러 번 malloc 시켜도 주소가 같은가?
    - malloc 함수가 힙 영역에 빈 공간을 찾아서 다른 주소를 부여한다.
- 재귀함수를 사용하는데 return 값 없이 재귀함수를 사용했다.
    - cpu 영역에서 잘못 처리하여 심각한 오류가 발생할 수 있으므로 우선 재귀를 사용할 때 return 값으로 함수를 받도록 했다.
- singly linked list를 만들 때 insert와 delete를 실행하기 위해 도착 해야하는 노드가 어려웠음.
    - insert: 삽입하려는 **전** 노드에서 insert 실행
    - delete: 삭제하려는 **전전** 노드에서 delete 실행
- 구조체 포인터를 선언 후 NULL로 초기화 시키지 않았음.
    - 쓰레기 값을 갖기 때문에 엉뚱한 결과가 나올 수 있다. 반드시 초기화 할 것.
- circular doubly linked list를 구현할 때 원형을 어떻게 구현할 지 몰랐음
    - data를 담지 않는 head 노드를 만들어서 시작과 끝을 연결하여 만듦.
