/**
 * @description Ýkili arama aðaçlarý üzerinde eleman ekleme, eleman silme ve soy sayýsýný bulma gibi çeþitli iþlemler yapýlýyor.
 * @course  Örgün Eðitim 2.Sýnýf
 * @assignment  3
 * @date  15.12.2019
 * @author Davud Samed Tombul(b171210007@sakarya.edu.tr)
 **/
#include <iostream>

class BSTNode {

private:

	int veri;

	int child_count = 0;

public:

	BSTNode* sol;

	BSTNode* sag;

	BSTNode(int);

	void setNumberofChild(int);

	int getNumberofChild(BSTNode*);

	BSTNode();

	int getNumberofChild();

	int get_data();

	void set_data(int);

};
