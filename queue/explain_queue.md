# Queue

# Queue란?

- FIFO(First In First Out, 선입선출)의 형태를 띈 추상적 자료구조이다.
- queue의 사전적 의미로는 대기열을 뜻한다.

# 규칙

- 데이터의 추가는 뒤에서 출력은 앞에서 진행된다. (FIFO)

# 연산

## enqueue

- 큐의 뒤에 데이터를 추가한다.

## dequeue

- 큐의 앞에 데이터를 조회하고 추가한다.

## front

- 맨 앞 데이터를 조회한다.

## is_empty

- 비어있는지 확인한다.

## is_full

- 가득 차 있는지 확인

# 사용 예시

- 대기 번호표, 롤 큐 등

# 직면했던 문제

- printf(”%d %d”, q→rear, q→rear++)를 했는데 결과가 0 -1로 반대로 나옴
    - why? C언어는 어떤 인자를 먼저 계산할 지 정해 놓지 않았다. 따라서 q→rear++을 먼저 계산하고 q→rear를 계산해서 이런 결과가 나왔다. q→rear와 q→ rear++의 위치는 정해져 있지만 계산 순서는 정해져 있지 않다.
    - 방지법: 함수 하나에 같은 인자를 두 번 이상 쓸 때는 해당 인자를 조심해서 바꿔야 한다.
- 원형 큐를 만들 때 empty와 full을 판별할 때 front와 rear의 값을 size로 나눈 나머지를 저장하니 판별에 어려움을 겪음.
    - front와 rear를 계속해서 증가 시키고 각각의 관계를 empty와 full에 적용 시켜서 판별했다.(Ex: front와 rear가 같으면 empty, rear - front가 size라면 full)
    - 큐의 한 칸을 남겨 놓아서 그 칸을 활용하여 empty와 full을 판별하는 방식또한 존재한다.
