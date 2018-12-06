#include <iostream>
#include <stdlib.h>
using namespace std;

typedef int infotype;
typedef struct tNode *address;
typedef struct tNode {
	infotype info;
	address left;
	address right;
} Node;

typedef address BinTree;

#define Akar(P) (P)->info
#define Left(P) (P)->left
#define Right(P) (P)->right
#define Nil NULL
#define empty(P) (P==NULL)

void CreateEmpty(BinTree *P) {
	*P = NULL;
}

address Allocation(infotype X) {
	address nodeBaru;
	nodeBaru = (Node*) malloc (sizeof(Node));
	
	Akar(nodeBaru) = X;
	Left(nodeBaru) = NULL;
	Right(nodeBaru) = NULL;
	
	return nodeBaru;
}

BinTree Tree (infotype Akar, BinTree L, BinTree R) {

	BinTree T;

	T = Allocation(Akar);
	if (T != Nil) {
		Left(T) = L;
		Right(T) = R;	
	}
	return T;
}

bool IsTreeEmpty(BinTree P) {
	return (P == NULL);
}

bool IsTreeOneElmt(BinTree P) {
	if (P!=NULL) {
		return (Left(P)==NULL && Right(P)==NULL);
	} else {
		return false;
	}
}

bool IsUnerLeft(BinTree P) {
	if (P!=NULL) {
		return (Left(P)!=NULL && Right(P)==NULL);
	} else {
		return false;
	}
}

bool IsUnerRight(BinTree P) {
	if (P!=NULL) {
		return (Left(P)==NULL && Right(P)!=NULL);
	} else {
		return false;
	}
}

void InsertNum(BinTree *P, infotype X) {
	
	if(empty(*P)) {
        *P=Allocation(X);
        return;
    }
    if(Akar(*P)==X) {
        return;
    }
    
    if(X<Akar(*P)) InsertNum(&Left(*P),X);
    else InsertNum(&Right(*P),X);

}

void PrintPreorder(BinTree P) {
	if (!IsTreeEmpty(P)) {
		PrintPreorder(Left(P));
		cout << Akar(P) << endl;
		PrintPreorder(Right(P));
	}
}

int NbDaun(BinTree P) {
	if (IsTreeOneElmt(P)) {
		return 1;
	} else {
		if (IsUnerLeft(P)) {
			return (NbDaun(Left(P)));
		} else if (IsUnerRight(P)) {
			return (NbDaun(Right(P)));
		} else {
			return (NbDaun(Left(P)) + NbDaun(Right(P)));
		}
	}
}

int NbElmt(BinTree P) {
	if (IsTreeEmpty(P)) {
		return 0;
	} else {
		return (1 + NbElmt(Left(P)) +NbElmt(Right(P)));
	}
}

int Tinggi(BinTree P) {
	int tLeft, tRight;
	
	if (IsTreeEmpty(P)) {
		return 0;
	} else {
		tLeft = Tinggi(Left(P));
		tRight = Tinggi(Right(P));
		
		if (tLeft > tRight) {
			return (1 + tLeft);
		} else {
			return (1 + tRight);
		}
	}
}

bool SearchTree(BinTree P, infotype X) {
	if (IsTreeEmpty(P)) {
		return false;
	} else {
		if (Akar(P) == X) {
			return true;
		} else {
			return (SearchTree(Left(P),X) || SearchTree(Right(P),X));
		}
	}
}

int LevelSearch(BinTree P, infotype X) {
	if (SearchTree(P, X)) {
		if (Akar(P) == X) {
			return 1;
		} else {
			if (X < Akar(P)) {
				return (1+LevelSearch(Left(P),X));
			} else {
				return (1+LevelSearch(Right(P),X));
			}
		}
	} else {
		return 0;
	}
}

int main(){
	BinTree T ;
	CreateEmpty(&T);
	InsertNum(&T,50);
    InsertNum(&T, 30); 
    InsertNum(&T, 20); 
    InsertNum(&T,50);
    InsertNum(&T, 40); 
    InsertNum(&T, 70); 
    InsertNum(&T, 60); 
    InsertNum(&T, 80);
	PrintPreorder(T);

}

