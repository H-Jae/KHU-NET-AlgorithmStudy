# Dynamic Programming

- 최적화 이론
- 사용하기 위한 조건이 따른다.
    1. Overlapping Subproblems (겹치는 부분 문제)
    2. Optimal Substructure (최적 부분 구조)

---

#### 어떻게 사용하면 될까?

##### 조건

1. Overlapping Subproblems
    - 반복적으로 부분 문제들이 나온다면 사용해주자 (부분 문제의 결과를 저장한다)

    ##### Ex) 막대기 자르기 문제

        하나의 긴 막대기가 있다. 이 막대기는 조각마다 가격이 다르다. 막대기를 적절히 잘라 가격이 높게 만들어보자.
        Sol) 길이가 n인 막대기의 최대 가격을 n이라고 하자. 
             Rn = max(val_i + Rn-i)라는 점화식으로 표현 가능하다.
             부분 문제가 반복적이다 -> 점화식 작성이 가능하다.
2. Optimal Substructure
    - 부분 문제의 최적 결과값 -> 전체 문제의 최적 결과값으로 도출되는 경우

      막대기 자르기 문제를 참고해보자.

##### 과정

1. 조건에 부합한지 확인해준다.
2. 문제의 변수를 파악해준다.
3. 변수 간 점화식을 만들어준다.```
4. 메모이제이션 , 즉 변수의 값에 따른 결과를 저장해준다.
5. 기저 상태 파악
6. 구현해준다.
    - Bottom-Up (반복문 사용) : dp[0] -> dp[n]
    - Top-Down (재귀 사용)

