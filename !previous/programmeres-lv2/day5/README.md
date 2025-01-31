이진수 문제는 비트 연산을 잘 쓰면 아이디어가 나온다!


다리를 지나는 트럭 문제는 시간 계산을 위해 queue에 0을 집어넣는 방법이 있다!!


소수 찾기는 next_permutation의 원소를 하나씩 다 긁으면 좀 더 간편하게 찾을 수 있다..!
 do {
        string temp = "";
        for (int i = 0; i < v.size(); i++) {
            temp.push_back(v[i]);
            nums.push_back(stoi(temp));
        }
    } while (next_permutation(v.begin(), v.end()));
이런식으로 하면 n! x n 으로 간편하게 구할 수 있다. 재귀보다 나은거 같다.