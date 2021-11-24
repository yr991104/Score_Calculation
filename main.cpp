#include <iostream>
#include <stdio.h>
#include <string.h>
#include <cassert>
#include <cstdlib>
#include <vector>

using namespace std;

vector<string> first_semester = { "디지털논리","이산구조","고급프로그래밍","리눅스활용실습","공학수학1" };		//1학기 공통과목
vector<string> second_semester = { "객체지향프로그래밍","선형대수학","자료구조","시스템소프트웨어","자료구조실습","오픈소스소프트웨어개발" };		//2학기 공통과목
vector<string> commons;			//이번 학기 공통과목 저장하는 문자열 벡터

int limit = 4;			//최대이수학점 21학점
int current_grades = 0;	//현재 수강신청한 학점
int semester;
vector<string> select;		//선택한 과목 저장할 문자열 벡터

class Sub {
private:
	string class_name;		//과목명
	string professor;		//담당교수님
	int point;				//학점(수업시수)
	int students;			//학생수
	int att;				//성적반영비율(출석, 중간고사, 기말고사, 과제, 퀴즈)
	int mid;
	int fin;
	int work;
	int quiz;
	int att_exp;			//기대평균치(출석, 중간고사, 기말고사, 과제, 퀴즈)
	int mid_exp;
	int fin_exp;
	int work_exp;
	int quiz_exp;
	double score_att = 0;	//취득점수(출석, 중간고사, 기말고사, 과제, 퀴즈)
	double score_mid = 0;	
	double score_fin = 0;
	double score_work = 0;
	double score_quiz = 0;
public:
	void ask_subject_info(string name);						//과목 정보 입력

	string getClassName() { return this->class_name; }		//정보 받아오기
	string getProfessor() { return this->professor; }
	int getStudent() { return this->students; }
	int getAtt() { return this->att; }
	int getMid() { return this->mid; }
	int getFin() { return this->fin; }
	int getWork() { return this->work; }
	int getQuiz() { return this->quiz; }
	int getAttExp() { return this->att_exp; }
	int getMidExp() { return this->mid_exp; }
	int getFinExp() { return this->fin_exp; }
	int getWorkExp() { return this->work_exp; }
	int getQuizExp() { return this->quiz_exp; }
	double getScoreAtt() { return this->score_att; }
	double getScoreMid() { return this->score_mid; }
	double getScoreFin() { return this->score_fin; }
	double getScoreWork() { return this->score_work; }
	double getScoreQuiz() { return this->score_quiz; }

	void setScoreAtt(double score) { score_att = score; }		//점수 입력하기
	void setScoreMid(double score) { score_mid = score; }
	void setScoreFin(double score) { score_fin = score; }
	void setScoreWork(double score) { score_work = score; }
	void setScoreQuiz(double score) { score_quiz = score; }
};

void show_subject(int semester) {		//학기 공통과목 출력
	cout << endl;
	cout << semester << "학기 공통과목입니다." << endl;
	if (semester == 1)			//1학기
	{
		for (string a : first_semester)
		{
			cout << a << "  ";
			commons.push_back(a);		//공통과목 저장
		}
		cout << endl;
	}
	else						//2학기
	{
		for (string a : second_semester)
		{
			cout << a << "  ";
			commons.push_back(a);		//공통과목 저장
		}
		cout << endl;
	}
	cout << endl;
}

vector<string> subject_select(vector<string> select)		//과목 선택 함수
{
	cout << "================================" << endl << endl;
	cout << "2학년 몇 학기 입니까? (1/2) : ";
	cin >> semester;
	if (semester == 1 || semester == 2)
	{
		show_subject(semester);
	}
	else
	{
		cout << "잘못된 입력입니다." << endl;
		subject_select(select);
	}

	cout << "입력을 종료하려면 q를 입력하세요." << endl << endl;

	while (current_grades <= 21)
	{
		string choose;			//입력받는 수강 과목명
		int cnt = 0;
		cout << "공통과목 중 수강할 과목 선택 : ";
		cin >> choose;

		if (choose == "q")
			break;

		for (string a : commons)
		{
			if (a == choose) {
				cnt++;			//선택한 과목이 해당학기 공통과목에 있을 시 cnt를 증가시키고 반복문을 빠져나온다.
				break;
			}
		}

		if (cnt == 1)			//cnt가 1이라는 것은 선택한 과목이 해당학기 공통과목에 존재한다는 의미이다.
		{
			int num = 0;

			for (string a : select)
			{
				if (a == choose) {
					num++;		//choose과 입력한 과목이 이미 select 벡터 안에 존재하는 값과 동일하면 num을 증가시키고 반복문 빠져나온다.
					break;
				}
			}

			if (num == 1)	//num이 1이라는 것은 select 벡터 안에 choose와 같은 값이 존재하는 것이다.
			{
				cout << "해당과목을 이미 신청하셨습니다.";
				cout << endl;
			}

			else			//num이 1이 아닌 경우 즉 select 벡터 안에 choose와 동일한 값이 없다는 것이다. 
			{
				select.push_back(choose);					//select안에 choose를 추가시킨다.

				if (choose.find("실습") != string::npos)		//실습과목인 경우 현재 신청한 학점이 2점 추가된다.
				{
					current_grades += 2;
				}
				else		//실습과목이 아닌 경우 현재 신청한 학점이 3점 추가된다.
				{
					current_grades += 3;
				}
			}
		}

		else			//cnt가 1이 아닌 경우 즉 0 인경우 선택한 과목이 해당 학기 공통과목에 없다는 것을 의미한다. 
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

	return select;
}

void print_subject(vector<string> select)		//선택 과목 출력
{
	cout << endl;
	cout << "=============현재 수강중인 과목=============" << endl<<endl;
	for (string a : select)
		cout << a << " ";
	cout << endl << endl << "=============================================" << endl;
}

void Sub::ask_subject_info(string name) {			//class의 변수를 이용한 과목 정보 입력
	cout << "과목명 : " << name << endl;
	class_name = name;
	cout << "담당교수 : ";
	cin >> professor;
	cout << "해당과목 수강인원 : ";
	cin >> students;
	cout << "성적 반영 비율 (출석, 중간, 기말, 과제, 퀴즈 비율 순) : ";
	cin >> att >> mid >> fin >> work >> quiz;
	cout << "기대 평균치 (출석, 중간, 기말, 과제, 퀴즈 비율 순) : ";
	cin >> att_exp >> mid_exp >> fin_exp >> work_exp >> quiz_exp;
}

vector<Sub> input_subject_info(vector<string> select, vector<Sub> sub_vec)			//수강중인 과목 전체 정보 입력 호출
{
	for (int i = 0; i < select.size(); i++) {
		Sub s;
		cout << endl << "성적 산출을 위한 정보를 입력해주세요" << endl;
		s.ask_subject_info(select.at(i));		//과목을 지정하여 정보 입력 함수 호출
		cout << endl;
		sub_vec.push_back(s);
	}

	return sub_vec;			//sub_vec를 리턴하여 과목 정보 리턴
}

vector<Sub> add_subject(vector<string> select, vector<Sub> sub_vec)			//과목 추가 함수
{
	string name;
	Sub s;

	cout << endl << "과목명을 입력하세요 : ";
	cin >> name;

	s.ask_subject_info(name);		//입력받은 과목명의 과목 정보

	if (current_grades <= limit)	//학점을 초과하지 않은 경우
	{
		sub_vec.push_back(s);			//sub_vec에 과목 정보 추가

		cout << endl << "입력되었습니다." << endl;
	}
	else							//학점을 초과한 경우
		cout << endl << "수강 가능 학점을 초과합니다." << endl;

	return sub_vec;			//sub_vec를 리턴하여 과목 정보 리턴
}

vector<Sub> input_subject_score(vector<Sub> sub_vec, string name)		//취득 점수 입력
{
	vector<Sub>::iterator iter;
	double score;

	for (iter = sub_vec.begin(); iter != sub_vec.end(); iter++)
	{
		if (iter->getClassName() == name)			//과목명을 class에서 찾기
		{
			cout << endl << "출석 점수 : ";			//점수 입력받기 및 설정하기
			cin >> score;
			iter->setScoreAtt(score);
			cout << "중간고사 점수 : ";
			cin >> score;
			iter->setScoreMid(score);
			cout << "기말고사 점수 : ";
			cin >> score;
			iter->setScoreFin(score);
			cout << "과제 점수 : ";
			cin >> score;
			iter->setScoreWork(score);
			cout << "퀴즈 점수 : ";
			cin >> score;
			iter->setScoreQuiz(score);
		}
	}

	return sub_vec;
}

string get_subject_score(vector<Sub> sub_vec, string name)		//입력받은 취득 점수로 학점 계산
{
	vector<Sub>::iterator iter;
	string sc;
	int Expscore;
	int myScore;
	int Ap, Az, Bp, Bz, Cp, Cz;
	int n1, n2;

	for (iter = sub_vec.begin(); iter != sub_vec.end(); iter++)
	{
		if (iter->getClassName() == name)
		{
			Expscore = (iter->getAttExp() * iter->getAtt() / 100) + (iter->getMidExp() * iter->getMid() / 100) + (iter->getFinExp() * iter->getFin() / 100) + (iter->getWorkExp() * iter->getWork() / 100)
				+ (iter->getQuizExp() * iter->getQuiz() / 100);
			myScore = (iter->getScoreAtt() * iter->getAtt() / 100) + (iter->getScoreMid() * iter->getMid() / 100) + (iter->getScoreFin() * iter->getFin() / 100) + (iter->getScoreWork() * iter->getWork() / 100)
				+ (iter->getScoreQuiz() * iter->getQuiz() / 100);

		}
	}

	n1 = 100 - Expscore;
	n2 = Expscore;

	Ap = 100 - n1 * 15 / 50;
	Az = Ap - n1 * 15 / 50;
	Bp = Az - n1 * 20 / 50;
	Bz = Bp - n2 * 20 / 50;
	Cp = Bz - n2 * 10 / 50;
	Cz = Cp - n2 * 10 / 50;

	if (myScore >= Ap)
		sc = "A+";
	else if (myScore >= Az)
		sc = "A0";
	else if (myScore >= Bp)
		sc = "B+";
	else if (myScore >= Bz)
		sc = "B0";
	else if (myScore >= Cp)
		sc = "C+";
	else if (myScore >= Cz)
		sc = "C0";
	else
		sc = "F";

	return sc;
}

int main(void)
{
	vector<Sub>::iterator iter;
	vector<Sub> sub_vec;

	select = subject_select(select);			//과목 선택

	print_subject(select);						//선택한 과목 출력

	sub_vec = input_subject_info(select , sub_vec);			//과목 정보 입력
	
	cout << "==================================" << endl;
	cout << "성적입력이 완료되었습니다." << endl;
	cout << "1. 과목 학점 계산" << endl;
	cout << "2. 과목 추가" << endl;
	cout << "3. 수강중인 과목 조회" << endl;
	cout << "4. 프로그램 종료" << endl;
	cout << "==================================" << endl << endl;
	cout << "원하시는 기능을 선택해 주세요 : ";

	int usrc;
	cin >> usrc;
	string usrchoice;
	
	while (usrc != 4)
	{
		int a = 0;
		int point = 0;

		switch (usrc)
		{
		case 1:
			cout << endl << "과목명을 입력하세요: ";
			cin >> usrchoice;
			for (iter = sub_vec.begin(); iter != sub_vec.end(); iter++) {			//sub_vec의 시작부터 끝까지 탐색
				if (iter->getClassName() == usrchoice) {					//입력받은 과목명과 같은 경우
					sub_vec = input_subject_score(sub_vec, usrchoice);				//취득점수 입력받기
					string score = get_subject_score(sub_vec, usrchoice);					//학점 구하기
					cout << endl << "해당과목의 예상 학점은 " << score << "입니다" << endl;
					a = 1;
					break;
				}
			}
			if(a != 1)			//과목명이 없는 경우
				cout << "수강하지 않은 과목입니다." << endl;
			break;
		case 2:
			if (current_grades == limit)		//이미 수강 가능 학점이 다 찬 경우
			{
				cout << "더 이상 과목을 수강할 수 없습니다." << endl;
				break;
			}

			cout << "수강할 과목의 학점 : ";
			cin >> point;
			current_grades += point;
			if (current_grades > limit)			//새롭게 수강할 과목이 초과학점이 될 경우
			{
				cout << "수강 가능 학점을 초과합니다." << endl;
				current_grades -= point;
				break;
			}

			sub_vec = add_subject(select, sub_vec);					//과목 추가
			select.push_back(sub_vec.back().getClassName());		//select에도 과목명 추가
			break;
		case 3:
			print_subject(select);
			break;
		}

		cout << endl << "==================================" << endl;
		cout << "원하시는 기능을 선택해 주세요 : ";
		cin >> usrc;
	}

	return 0;

}