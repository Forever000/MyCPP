#pragma once
#include"boost/archive/xml_iarchive.hpp"
#include"boost/archive/xml_oarchive.hpp"
#include"boost/serialization/vector.hpp"
#include"boost/serialization/list.hpp"
#include<fstream>
#include<iterator>
#include<algorithm>


class date
{
public:
	date(int d,int m,int y):m_day(d),m_month(m),m_year(y){}
	date() :m_day(1), m_month(1), m_year(1) {}
	~date(){}

	friend std::ostream& operator << (std::ostream& out, date& d) {
		out << "d.m_day:" << d.m_day << "-d.m_month:" << d.m_month << "-d.m_year:" << d.m_year << std::endl;
		return out;
	}


private:
	friend class boost::serialization::access;
	template<typename T>
	void serialize(T& archive, const unsigned int version) {
		archive & BOOST_SERIALIZATION_NVP(m_day);
		archive & BOOST_SERIALIZATION_NVP(m_month);
		archive & BOOST_SERIALIZATION_NVP(m_year);
	}
	unsigned int m_day;
	unsigned int m_month;
	unsigned int m_year;

};