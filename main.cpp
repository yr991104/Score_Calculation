#include <iostream>
#include <stdio.h>
#include <string.h>
#include <cassert>
#include <cstdlib>
#include <vector>
//test용
using namespace std;

vector<string> first_semester = { "디지털논리","이산구조","고급프로그래밍","리눅스활용실습","공학수학1" };//1학기 공통과목
vector<string> second_semester = { "객체지향프로그래밍","선형대수학","자료구조","시스템소프트웨어","자료구조실습","오픈소스소프트웨어개발" };//2학기 공통과목
vector<string> commons;//이번 학기 공통과목 저장하는 문자열 벡터

//과목 클래스
class Sub {
private:
	string class_name;
	string professor;
	int students;
	double att;
	double mid;
	double fin;
	double quiz;
	int score_mid;
	int score_fin;
	int score_quiz;
public:
	void ask_subject_info();
	string getClassName() { return this->class_name; }
	//char getGrade();
};
void Sub::ask_subject_info() {

	cout << "과목명: ";
	cin >> class_name;
	cout << "담당교수 : ";
	cin >> professor;
	cout << "점수(중간, 기말, 과제 순): ";
	cin >> score_mid >> score_fin >> score_quiz;
	cout << "해당과목 수강인원: ";
	cin >> students;
	cout << "성적 반영 비율을 입력하세요(출석, 과제, 중간, 기말 비율 순): ";
	cin >> att >> mid >> fin >> quiz;
}
/*char Sub::getGrade() {

}*/



void show_subject(int semester) {
	cout << endl;
	cout << semester << "학기 공통과목입니다." << endl;
	if (semester == 1)
	{
		for (string a : first_semester)
		{
			cout << a << "  ";
			commons.push_back(a);
		}
		cout << endl;
	}
	else
	{
		for (string a : second_semester)
		{
			cout << a << "  ";
			commons.push_back(a);
		}
		cout << endl;
	}
	cout << endl;
}
int main(void)
{
	vector<string> select;//선택한 과목 저장할 문자열 벡터
	int limit = 21;//최대이수학점 21학점
	int current_grades = 0;//현재 수강신청한 학점
	int semester;
restart:
	cout << "2학년 몇 학기 입니까? (1/2) : ";
	cin >> semester;
	if (semester == 1 || semester == 2)
	{
		show_subject(semester);
	}
	else
	{
		cout << "잘못된 입력입니다." << endl;
		goto restart;
	}
	while (current_grades <= 21)
	{
		string choose;
		int cnt = 0;
		cout << "공통과목 중 수강할 과목 선택 : " << endl;
		cout << "과목 입력을 종료하려면 stop_sub를 입력하시오" << endl;
		cin >> choose;
		if (choose == "stop_sub") {
			break;
		}
		for (string a : commons)
		{
			if (a == choose) {
				cnt++;//선택한 과목이 해당학기 공통과목에 있을 시 cnt를 증가시키고 반복문을 빠져나온다.
				break;
			}
		}
		if (cnt == 1)//cnt가 1이라는 것은 선택한 과목이 해당학기 공통과목에 존재한다는 의미이다.
		{
			int num = 0;
			for (string a : select)
			{
				if (a == choose) {
					num++;//choose과 입력한 과목이 이미 select 벡터 안에 존재하는 값과 동일하면 num을 증가시키고 반복문 빠져나온다.
					break;
				}
			}
			if (num == 1)//num이 1이라는 것은 select 벡터 안에 choose와 같은 값이 존재하는 것이다.
			{
				cout << "해당과목을 이미 신청하셨습니다.";
				cout << endl;
			}
			else//num이 1이 아닌 경우 즉 select 벡터 안에 choose와 동일한 값이 없다는 것이다. 
			{
				select.push_back(choose);//select안에 choose를 추가시킽다.
				if (choose.find("실습") != string::npos)//실습과목인 경우 현재 신청한 학점이 2점 추가된다.
				{
					current_grades += 2;
				}
				else//실습과목이 아닌 경우 현재 신청한 학점이 3점 추가된다.
				{
					current_grades += 3;
				}
			}
		}
		else//cnt가 1이 아닌 경우 즉 0 인경우 선택한 과목이 해당 학기 공통과목에 없다는 것을 의미한다. 
		{
			cout << "해당과목은 이번학기 공통과목에 없습니다.";
			cout << endl;
		}

		cout << "현 수강신청한 과목 목록 : ";
		for (string a : select)
		{
			cout << a << " ";
		}
		cout << endl;
		cout << "현재 신청한 학점 : " << current_grades << endl;
		cout << endl;
	}




	vector<Sub> sub_vec;
	vector<Sub>::iterator iter;

	for (int i = 0; i < select.size(); i++) {
		Sub s;
		cout << " 성적 산출을 위한 정보를 입력해주세요" << endl;
		s.ask_subject_info();
		cout << endl;
		sub_vec.push_back(s);

	}

	cout << "성적입력이 완료되었습니다. 원하시는 기능을 선택해 주세요" << endl;
	cout << "1. 해당과목 학점 계산" << endl;
	cout << "2. 전체 학점 계산" << endl;
	cout << "3. 프로그램 종료" << endl;
	int usrc;
	cin >> usrc;
	string usrchoice;
	switch (usrc)
	{
	case 1:
		cout << "무슨 과목의 학점을 계산하길 원하시나요?: ";
		cin >> usrchoice;
		for (iter = sub_vec.begin(); iter != sub_vec.end(); iter++) {
			if (iter->getClassName() == usrchoice) {
				cout << "해당과목의 예상 학점은 " << "A" << "입니다" << endl;
			}
		}
		break;
	case 3:
		break;
	default:
		break;
	}
	return 0;

}