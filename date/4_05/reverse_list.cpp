#include<iostream>
#include<vector>

using namespace std;

template<class type>
struct List {
	type val;
	List* next=nullptr;
};

//新建链表
template<class type,class T>
void newlist(T first, T last,List<type>*& h) {
	auto head = new List<type>;
	head->val = *first;
	auto p = head;
	for (auto it = first+1; it != last; ++it) {
		auto m = new List<type>;
		m->val = *it;
		p->next= m;
		p = m;
	}
	h = head;
}

//反转链表
template<class type>
List<type>* reverseList(List<type>*& head) {
	if (head == nullptr)	return nullptr;
	auto q = head;
	auto p = q->next;
	if (p == nullptr)
		return q;
	q->next = nullptr;
	auto m = p->next;
	if (m == nullptr)
	{
		p->next = q;
		
		return p;
	}
	while (m != nullptr){
		p->next = q;
		q = p;
		p = m;
		m = m->next;
	} 
	p->next = q;
	return p;
}

//销毁链表
template<class type>
void deletelist(List<type>*& head) {
	List<type>* p;
	while (head != nullptr) {
		p = head->next;
		delete head;
		head = p;
	}
}

int main() {
	int tmp;
	vector<int> vec;
	while (cin >> tmp) {
		vec.push_back(tmp);
	}

	List<int>* head;
	newlist(vec.begin(), vec.end(),head);
	auto p = head;
	
	while (p!= nullptr) {
		cout << p->val << ' ';
		p = p->next;
	}
	cout << endl;

	head = reverseList(head);
	p = head;
	while (p != nullptr) {
		cout << p->val << ' ';
		p = p->next;
	}
	cout << endl;
	deletelist(head);
}