#ifndef HASHMAP_H_INCLUDED
#define HASHMAP_H_INCLUDED

const int bucketsize = 1e5;
#define fi first
#define se second

struct Node {
	int e;
	Node* next;
	//Node(int e_,Node* next_):e(e_), next(next_){}
};


class hashmap {
public:

	hashmap() {
		bucket = new Node[bucketsize];

		for (int i = 0; i<bucketsize; i++) {
			bucket[i].e = INT_MIN;
			bucket[i].next = NULL;
		}
		elesize = 0;
	}

	int hashcode(int e) {
		return e % bucketsize;
	}

	int size() {
		return elesize;
	}

	void insert(int e) {
		int index = hashcode(e);
		if (bucket[index].e == e) return;
		Node* p = bucket[index].next;
		while (p && p->e != e) p = p->next;
		if (!p) {
			Node* newnode = new Node;
			newnode->e = e;
			newnode->next = bucket[index].next;
			bucket[index].next = newnode;
			elesize++;
		}
	}

	bool find(int e) {
		int index = hashcode(e);
		if (bucket[index].e == e) return 1;
		Node* p = bucket[index].next;
		while (p && p->e != e) p = p->next;
		return p;
	}

	void erase(int e) {
		int index = hashcode(e);
		if (bucket[index].e == e) {
			bucket[index].e = INT_MIN;
			elesize--;
			return;
		}
		Node* p = bucket[index].next, *pre = NULL;
		while (p && p->e != e) p = p->next, pre = p;
		if (!p) {
			if (!pre) bucket[index].next = p->next;
			else pre->next = p->next;
			delete p;
			elesize--;
		}
	}

private:
	Node*bucket;// [bucketsize];
	int elesize;
};

#endif // HASHMAP_H_INCLUDED
