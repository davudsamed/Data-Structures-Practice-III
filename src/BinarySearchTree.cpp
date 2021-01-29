/**
 * @description Ýkili arama aðaçlarý üzerinde eleman ekleme, eleman silme ve soy sayýsýný bulma gibi çeþitli iþlemler yapýlýyor.
 * @course  Örgün Eðitim 2.Sýnýf
 * @assignment  3
 * @date  15.12.2019
 * @author Davud Samed Tombul(b171210007@sakarya.edu.tr)
 **/
#include "BinarySearchTree.h"

void BinarySearchTree::bulVeSil(BSTNode*& altDugum, int data_)
{
	if (altDugum == NULL)
	{
		return;
	}
	if (data_ < altDugum->get_data())
	{
		return bulVeSil(altDugum->sol, data_);
	}
	else if (data_ > altDugum->get_data())
	{ 
		return bulVeSil(altDugum->sag, data_);
	}
	else if (data_ == altDugum->get_data())
	{ 
		Sil(altDugum);
	}
}

int BinarySearchTree::max(BSTNode* altDugum) {

	while (altDugum->sag != NULL) {

		altDugum = altDugum->sag;

	}

	int tempVal_ = altDugum->get_data();

	return tempVal_;
}

void BinarySearchTree::Ekle(BSTNode*& altDugum, int Data) {

	if (altDugum == NULL)
	{
		altDugum = new BSTNode(Data);
	}
	else if (Data <= altDugum->get_data())
	{
		Ekle(altDugum->sol, Data);
	}
	else if (Data > altDugum->get_data())
	{
		Ekle(altDugum->sag, Data);
	}
	else return;


}

void BinarySearchTree::postorder(BSTNode* altDugum) {

	dugum = new BSTNode;


	if (altDugum != NULL) {

		postorder(altDugum->sol);

		postorder(altDugum->sag);

		cout << " < " << altDugum->get_data() << "," << dugum->getNumberofChild(altDugum) << " > ";
	}

	delete dugum;
}

void BinarySearchTree::Oku() {

	int counter = 0;
	int veri_ = 0;

	file.open(".\\doc\\benim.txt", ios::in);

	while (file >> veri_) {

		Ekle(kok1, veri_);
	}
	file.close();
}

void BinarySearchTree::rakipOku() {

	int oponent_data = 0;
	int counter = 0;

	file.open(".\\doc\\rakip.txt", ios::in);

	while (file >> oponent_data) {

		Ekle(rakip_root, oponent_data);
	}
	file.close();
}

void BinarySearchTree::Hesapla()
{}

void BinarySearchTree::kazananKontrol() {
	
	int benimSkorum = 0;

	int rakipSkor = 0;

	int raund = 0;

	do {
		raund++;
		if (abs(rakipSkor - benimSkorum) == 5 || raund == 20)
			break;

		all_child = 0;

		all_child_OnMyLeaf = All_Child_Total(kok1);

		all_child = 0;

		all_child_OnOponentLeaf = All_Child_Total(rakip_root);

		yazdir(all_child_OnMyLeaf, all_child_OnOponentLeaf);

		if (all_child_OnMyLeaf < all_child_OnOponentLeaf)
		{
			Ekle(kok1, max(rakip_root));

			bulVeSil(rakip_root, max(rakip_root));

			Ekle(rakip_root, kok1->get_data());

			bulVeSil(kok1, kok1->get_data());

			benimSkorum++;

			cout << "\n\n-------------TEBRIKLER, TURU SIZ KAZANDINIZ-------------\n";
		}
		else if (all_child_OnMyLeaf > all_child_OnOponentLeaf)
		{
			Ekle(rakip_root, max(kok1));

			bulVeSil(kok1, max(kok1));

			Ekle(kok1, rakip_root->get_data());

			bulVeSil(rakip_root, rakip_root->get_data());

			rakipSkor++;

			cout << "\n\n--------------TEBRIKLER, TURU RAKIP KAZANDI--------------\n";
		}
		else if (all_child_OnMyLeaf == all_child_OnOponentLeaf)
		{

			int myData = kok1->get_data();

			int oponentData = rakip_root->get_data();

			bulVeSil(kok1, kok1->get_data());

			bulVeSil(rakip_root, rakip_root->get_data());

			Ekle(kok1, oponentData);

			Ekle(rakip_root, myData);

			cout << "\n\n--------------SONUC BERABERE--------------\n";
		}
		cout << "SKOR:\n" << "Benim : " << benimSkorum << "\nRakip : " << rakipSkor << endl << endl;

		system("pause");
	} while (1);
}

void BinarySearchTree::basla() {

	system("cls");

	rakipOku();

	Oku();

	kazananKontrol();

}

BinarySearchTree::~BinarySearchTree() {



	delete dugum;

	delete node_temp;

	delete N_iter;

	delete parentNode;


}

bool BinarySearchTree::Sil(BSTNode*& altDugum)
{

	parentNode = altDugum;

	N_iter = altDugum;
	


	if (altDugum->sol == NULL)
	{ 
		altDugum = altDugum->sag;
	}
	//Tek Sol Çocuklu
	else if (altDugum->sag == NULL)
	{
		altDugum = altDugum->sol;
	}
	else {
		N_iter = altDugum->sol;
		while (N_iter->sag != NULL) {

			parentNode = N_iter;

			N_iter = N_iter->sag;

		}
		altDugum->set_data(N_iter->get_data());

		if (parentNode == altDugum)
		{
			altDugum->sol = N_iter->sol;
		}
		else
			parentNode->sag = N_iter->sol;
	}

	delete N_iter;

	return true;

}

void BinarySearchTree::yazdir(int myallChild, int oponentallChild) {

	cout << "Benim Agac Postorder :" << endl;

	postorder(kok1);

	cout << "\nBenim Agac Toplam Soy Sayisi : " << myallChild << endl;

	cout << "\n-------------------------------------" << endl;

	cout << "Rakip Agac Postorder :" << endl;

	postorder(rakip_root);

	cout << "\nRakip Agac Toplam Soy Sayisi : " << oponentallChild << endl;

}

int BinarySearchTree::All_Child_Total(BSTNode* altDugum)
{
	dugum = new BSTNode;

	if (altDugum != NULL) {

		All_Child_Total(altDugum->sol);

		All_Child_Total(altDugum->sag);

		dugum->setNumberofChild(dugum->getNumberofChild(altDugum));

		all_child += dugum->getNumberofChild();

	}

	delete dugum;

	return all_child;

}

