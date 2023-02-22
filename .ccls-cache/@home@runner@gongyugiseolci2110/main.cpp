#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n, m; //첫째줄 
int st, cot; //최근 공유기 설치 위치, 공유기 설치 수,
int Start, End, mid, ans = 0; //집의 거리를 대상으로 이분탐색하기 위한 변수들 및 정답

vector<int> Home; // 집 위치 저장

//입력 및 정렬
void Input()
{
  int k;
  
  cin >> n >> m;
  
  for(int i = 0; i < n; i++) 
  {
    cin >> k;
    Home.push_back(k);
  }
}

// 이분탐색 준비
void Set()
{
  sort(Home.begin(), Home.end());

  Start = 1; // 최솟값
  End = Home[n-1] - Home[0]; // 최댓값 
}

// 탐색실행
void Sol()
{
  while (Start <= End)
	{
		cot = 1;
    
		mid = (Start + End) / 2; 
		st = Home[0];

		for (int i = 1; i < n; i++)
		{
			if (Home[i] - st >= mid)
			{
				cot++;
				st = Home[i];
			}
		}

		if (cot >= m)
		{
			if (ans < mid) ans = mid;
      
			Start = mid + 1;
		}
		else
			End = mid - 1;
	}
	cout << ans;
}

int main() 
{
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  
  Input();
  Set();
  Sol();
}