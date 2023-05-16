#include<iostream>
using namespace std;

struct TNode {
	int data;
	TNode* pleft;
	TNode* pright;
};

void CreateTNode(TNode* &t) {
	t = NULL;
}


void AddNode(TNode* &t, int x) {
	if (t == NULL) {
		TNode* NewTNode = new TNode;
		NewTNode->data = x;
		NewTNode->pleft = NULL;
		NewTNode->pright = NULL;
		t = NewTNode;
	}
	else {
		if (x < t->data) {
			AddNode(t->pleft, x);
		}
		else if (x > t->data) {
			AddNode(t->pright, x);
		}
	}
}

void NLR(TNode* t) {
	if (t != NULL) {
		cout << t->data << " ";
		NLR(t->pleft);
		NLR(t->pright);
	}
	
}




void NRL(TNode* t) {
	if (t != NULL) {
		cout << t->data << " ";
		NRL(t->pright);
		NRL(t->pleft);
	}
	
}

bool soNguyenTo(int soA) // hàm bool trả về true/false
{
	if (soA < 2) // Nếu số A nhỏ hơn 2
	{
		return false;// trả về false
	}
	else if (soA > 2)// Nếu số A lớn hơn 2
	{
		if (soA % 2 == 0)  // Xét xem A có chia hết cho 2 không?
		{
			return false;// Nếu chia hết, return false.
		}
		for (int i = 3; i < sqrt((float)soA); i += 2)  // xét từ 3 đến căn bậc 2 của số A
		{
			if (soA % i == 0)  // nếu A chia hết cho một số nào đó trong đoạn này
			{
				return false;// trả về kết quả sai
			}
		}
	}
	return true;// sau tất cả các chỗ trên, nó mà không sai thì cuối cùng nó đúng :3
}

void xuatsnt(TNode* t) {
	if (t != NULL) {
		if (soNguyenTo(t->data)) {
			cout << t->data << " ";
		}
		xuatsnt(t->pleft);
		xuatsnt(t->pright);
	}
}

void LNR(TNode* t) {
	if (t != NULL) {
		LNR(t->pleft);
		cout << t->data << " ";
		LNR(t->pright);
	}

}




void RNL(TNode* t) {
	if (t != NULL) {
		RNL(t->pright);
		cout << t->data << " ";
		RNL(t->pleft);
	}
	
}

void LRN(TNode* t) {
	if (t != NULL) {
		LRN(t->pleft);
		LRN(t->pright);
		cout << t->data << " ";
	}
	
}

void RLN(TNode* t) {
	if (t != NULL) {
		RLN(t->pright);
		RLN(t->pleft);
		cout << t->data << " ";
	}

}



int main() {
	TNode* t;
	CreateTNode(t);
	while (true) {
		cout << endl << "=======================MENU=======================" << endl;
		cout << "1. Nhap" << endl;
		cout << "2. Xuat cac so nguyen to" << endl;
		cout << "3. LNR" << endl;
		cout << "0. Thoat" << endl;
		cout << "==================================================" << endl;
		int selection;
		cout << "Lua chon: ";
		cin >> selection;
		system("cls");
		if (selection < 0 or selection > 3) {
			cout << "Nhap sai. Vui long nhap lai!" << endl;
		}
		else if (selection == 1) {
			int x;
			cout << "Nhap: ";
			cin >> x;
			AddNode(t, x);
		}
		else if (selection == 2) {
			xuatsnt(t);
		}
		else if (selection == 3) {
			LNR(t);
		}
		else {
			cout << "Dang thoat...." << endl; break;
		}

	}
	
}
