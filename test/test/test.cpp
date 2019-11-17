#include "pch.h"
#include <iostream>
#include <vector>
#include <algorithm>

class CNodeStatic {
public:
	CNodeStatic();
	CNodeStatic(const CNodeStatic &pcOther);
	explicit CNodeStatic(CNodeStatic *pcParent);

	CNodeStatic & operator=(CNodeStatic const &pcOther);
	bool operator==(CNodeStatic const &pcOther);
	bool operator !=(CNodeStatic const &pcOther);

	void vSetValue(int iNewVal) { i_val = iNewVal; }
	int iGetChildrenNumber() { return v_children.size(); }
	void vAddNewChild();
	CNodeStatic *pcGetChild(int iChildOffset);
	void vPrint() { std::cout << " " << i_val; }
	void vPrintAllBelow();
	void vPrintUp();
	void vPrintUpAddresses();
	void vPrintAddressesAllBelow();
	bool bHasParent() { return pc_parent != NULL; }
	bool bUnpin();
	void vSetMyChildrenParents();
	void vSetParentsBelow();
	CNodeStatic *pc_parent;
private:
	std::vector<CNodeStatic> v_children;
	int i_val;
};

class CTreeStatic {
public:
	CNodeStatic *pcGetRoot() { return &c_root; }
	void vPrintTree();
	bool bMoveSubtree(CNodeStatic *pcParentNode, CNodeStatic *pcNewChildNode);
private:
	CNodeStatic c_root;
};


//Constructors

CNodeStatic::CNodeStatic() {
	i_val = 0;
	pc_parent = NULL;
}

CNodeStatic::CNodeStatic(const CNodeStatic &pcOther) {
	pc_parent = pcOther.pc_parent;
	v_children = pcOther.v_children;
	i_val = pcOther.i_val;
	vSetMyChildrenParents();
}

CNodeStatic::CNodeStatic(CNodeStatic *pcParent) {
	i_val = 0;
	pc_parent = pcParent;
}

//Operators
CNodeStatic& CNodeStatic::operator=(CNodeStatic const &pcOther) {
	pc_parent = pcOther.pc_parent;
	v_children = pcOther.v_children;
	i_val = pcOther.i_val;
	vSetMyChildrenParents();

	return *this;
}

bool CNodeStatic::operator==(CNodeStatic const &pcOther) {
	if (i_val != pcOther.i_val) {
		return false;
	}
	if (v_children.size() != pcOther.v_children.size()) {
		return false;
	}
	for (int i = 0; i < v_children.size(); i++) {
		if (v_children[i] != pcOther.v_children[i]) {
			return false;
		}
	}
	return true;
}
bool CNodeStatic::operator!=(CNodeStatic const &pcOther) {
	return !operator==(pcOther);
}
void CNodeStatic::vAddNewChild() {
	v_children.push_back(CNodeStatic(this));
}

CNodeStatic* CNodeStatic::pcGetChild(int iChildOffset) {
	return (iChildOffset >= 0 and iChildOffset < v_children.size()) ? &v_children[iChildOffset] : NULL;
}

void CNodeStatic::vPrintAllBelow() {
	vPrint();
	for (int i = 0; i < v_children.size(); i++) {
		v_children[i].vPrintAllBelow();
	}
}
void CNodeStatic::vPrintUp() {
	vPrint();
	if (pc_parent != NULL) {
		pc_parent->vPrintUp();
	}
}
void CNodeStatic::vPrintUpAddresses() {
	std::cout << this << " ";
	if (pc_parent != NULL) {
		pc_parent->vPrintUpAddresses();
	}
}
void CNodeStatic::vPrintAddressesAllBelow() {
	std::cout << this << " ";
	for (int i = 0; i < v_children.size(); i++) {
		v_children[i].vPrintAddressesAllBelow();
	}
}
void CNodeStatic::vSetMyChildrenParents() {
	for (int i = 0; i < v_children.size(); i++) {
		v_children[i].pc_parent = this;
	}
}
void CNodeStatic::vSetParentsBelow() {
	vSetMyChildrenParents();
	for (int i = 0; i < v_children.size(); i++) {
		v_children[i].vSetParentsBelow();
	}
}
bool CNodeStatic::bUnpin() {
	if (pc_parent == NULL) {
		return false;
	}
	std::vector <CNodeStatic> * pv_siblings = &(pc_parent->v_children);
	CNodeStatic* pc_temp_parent = pc_parent;
	pv_siblings->erase(std::remove(pv_siblings->begin(), pv_siblings->end(), *this), pv_siblings->end());
	pc_temp_parent->vSetMyChildrenParents();
	return true;
}

bool CTreeStatic::bMoveSubtree(CNodeStatic *pcParentNode, CNodeStatic *pcNewChildNode) {
	if (!pcNewChildNode->bHasParent()) {
		return false;
	}
	pcParentNode->vAddNewChild();
	CNodeStatic *pc_place = pcParentNode->pcGetChild(pcParentNode->iGetChildrenNumber() - 1);
	*pc_place = *pcNewChildNode;
	pcNewChildNode->bUnpin();
	pcParentNode->vSetMyChildrenParents();
	return true;
}

void CTreeStatic::vPrintTree() {
	c_root.vPrintAllBelow();
}

int main() {

}
