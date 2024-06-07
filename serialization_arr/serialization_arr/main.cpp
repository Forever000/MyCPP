#include<iostream>
#include"serialization_cusdata.h"
using namespace std;

void arrsave() {
	ofstream os("archieve.xml");
	boost::archive::xml_oarchive oa(os);
	int arr[] = {1,2,3,4,56,7,8};
	oa & BOOST_SERIALIZATION_NVP(arr);
	cout << "数组序列化完毕" << endl;

}
void vecsave() {
	ofstream os("archievec.xml");
	vector<int> vec = { 1,2,3,4,45,67,89 };
	boost::archive::xml_oarchive oa(os);
	oa & BOOST_SERIALIZATION_NVP(vec);
	cout << "vecsave()序列化完毕" << endl;
}


void arrload() {
	ifstream is("archieve.xml");
	boost::archive::xml_iarchive ia(is);
	int restroy[10];
	ia & BOOST_SERIALIZATION_NVP(restroy);
	ostream_iterator<int> oi(cout," ");
	copy(restroy, restroy + 7, oi);
	cout << "数组反序列化完毕" << endl;
}
void vecload() {
	ifstream is("archievec.xml");
	boost::archive::xml_iarchive ia(is);
	vector<int> inp;
	ia & BOOST_SERIALIZATION_NVP(inp);
	ostream_iterator<int> oa(cout," ");
	copy(inp.begin(), inp.end(), oa);
	cout << "vecload反序列化完毕" << endl;
}

void serialization_cusdata_test() {
	date da(8,3,2024);
	ofstream os("cusdata_serialization.xml");
	boost::archive::xml_oarchive oa(os);
	oa & BOOST_SERIALIZATION_NVP(da);
	cout << "serialization_cusdata_test()序列化完毕" << endl;
}
void serialization_cusdata_test_read() {
	ifstream is("cusdata_serialization.xml");
	boost::archive::xml_iarchive ia(is);
	date da;
	ia >> BOOST_SERIALIZATION_NVP(da);
	cout << da;

}


int main() {
	arrsave();
	arrload();
	vecsave();
	vecload();

	serialization_cusdata_test();
	serialization_cusdata_test_read();
	system("pause");
	return 0;
}