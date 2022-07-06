#include<iostream>

using namespace std;

int const MAX = 1002;
int map[MAX][MAX];
int QueenX[100],QueenY[100];
int KnightX[100],KnightY[100];
int MoveQueenX[8] = {-1,-1,0,1,1,1,0,-1};
int MoveQueenY[8] = {0,-1,-1,-1,0,1,1,1};

int MoveKnightX[8] = {2,2,-2,-2,1,1,-1,-1};
int MoveKnightY[8] = {1,-1,1,-1,2,-2,-2,2};

int main(){
	int currentBoard = 0;
	int N, M, currentPos, sumKnight, sumQueen, sumPawns;
	int tempy,tempx;

	//freopen("input.txt","r",stdin);

	while (true){
		cin >> N >> M;
		if (N == 0 && M == 0 ) return 0;


		for (int i = 1; i <= N; i++)
			for (int j = 1; j <= M; j++)
				map[i][j] = 0 ;

		currentBoard++;
		currentPos = 0;

		cin >> sumQueen;
		for (int i = 0; i < sumQueen; i++){
			cin >> QueenY[i] >> QueenX[i];
			map[QueenY[i]][QueenX[i]] = 1;
		}

		cin >> sumKnight;
		for (int i = 0; i < sumKnight; i++){
			cin >> KnightY[i] >> KnightX[i];
			map[KnightY[i]][KnightX[i]] = 1;
		}

		cin >> sumPawns;
		for (int i = 0; i < sumPawns; i++){
			cin >> tempy >> tempx;
			map[tempy][tempx] = 1;
		}

		// pos by Queen
		for (int i = 0; i < sumQueen; i++)
			for (int j = 0; j < 8; j++){
				tempy = QueenY[i];
				tempx = QueenX[i];
				tempx += MoveQueenX[j];
				tempy += MoveQueenY[j];
				if (tempy< 1 || tempy > N|| tempx<1 || tempx>M)
					continue;
				while (map[tempy][tempx] != 1){
					if (tempy < 1 || tempy > N|| tempx < 1 || tempx > M)
						break;
					if (map[tempy][tempx] == 0){
						currentPos++;
						map[tempy][tempx] = 2;
					}	
					tempx += MoveQueenX[j];
					tempy += MoveQueenY[j];
				}
			}

		// pos by Knight
		for (int i = 0 ; i < sumKnight; i++)
			for (int j = 0; j < 8; j++){
				tempy = KnightY[i] + MoveKnightY[j];
				tempx = KnightX[i] + MoveKnightX[j];
				if (tempy < 1 || tempy > N|| tempx < 1 || tempx > M)
					continue;
				if (map[tempy][tempx] == 0){
					currentPos++;
					map[tempy][tempx] = 2;
				}

			}
		cout << "Board " << currentBoard << " has " 
			<< N*M - currentPos - sumKnight - sumQueen - sumPawns << " safe squares." << endl;
	}
}