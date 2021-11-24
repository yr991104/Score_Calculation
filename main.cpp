#include <iostream>
#include <stdio.h>
#include <string.h>
#include <cassert>
#include <cstdlib>
#include <vector>

using namespace std;

vector<string> first_semester = { "�����г�","�̻걸��","������α׷���","������Ȱ��ǽ�","���м���1" };		//1�б� �������
vector<string> second_semester = { "��ü�������α׷���","���������","�ڷᱸ��","�ý��ۼ���Ʈ����","�ڷᱸ���ǽ�","���¼ҽ�����Ʈ�����" };		//2�б� �������
vector<string> commons;			//�̹� �б� ������� �����ϴ� ���ڿ� ����

int limit = 4;			//�ִ��̼����� 21����
int current_grades = 0;	//���� ������û�� ����
int semester;
vector<string> select;		//������ ���� ������ ���ڿ� ����

class Sub {
private:
	string class_name;		//�����
	string professor;		//��米����
	int point;				//����(�����ü�)
	int students;			//�л���
	int att;				//�����ݿ�����(�⼮, �߰����, �⸻���, ����, ����)
	int mid;
	int fin;
	int work;
	int quiz;
	int att_exp;			//������ġ(�⼮, �߰����, �⸻���, ����, ����)
	int mid_exp;
	int fin_exp;
	int work_exp;
	int quiz_exp;
	double score_att = 0;	//�������(�⼮, �߰����, �⸻���, ����, ����)
	double score_mid = 0;	
	double score_fin = 0;
	double score_work = 0;
	double score_quiz = 0;
public:
	void ask_subject_info(string name);						//���� ���� �Է�

	string getClassName() { return this->class_name; }		//���� �޾ƿ���
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

	void setScoreAtt(double score) { score_att = score; }		//���� �Է��ϱ�
	void setScoreMid(double score) { score_mid = score; }
	void setScoreFin(double score) { score_fin = score; }
	void setScoreWork(double score) { score_work = score; }
	void setScoreQuiz(double score) { score_quiz = score; }
};

void show_subject(int semester) {		//�б� ������� ���
	cout << endl;
	cout << semester << "�б� ��������Դϴ�." << endl;
	if (semester == 1)			//1�б�
	{
		for (string a : first_semester)
		{
			cout << a << "  ";
			commons.push_back(a);		//������� ����
		}
		cout << endl;
	}
	else						//2�б�
	{
		for (string a : second_semester)
		{
			cout << a << "  ";
			commons.push_back(a);		//������� ����
		}
		cout << endl;
	}
	cout << endl;
}

vector<string> subject_select(vector<string> select)		//���� ���� �Լ�
{
	cout << "================================" << endl << endl;
	cout << "2�г� �� �б� �Դϱ�? (1/2) : ";
	cin >> semester;
	if (semester == 1 || semester == 2)
	{
		show_subject(semester);
	}
	else
	{
		cout << "�߸��� �Է��Դϴ�." << endl;
		subject_select(select);
	}

	cout << "�Է��� �����Ϸ��� q�� �Է��ϼ���." << endl << endl;

	while (current_grades <= 21)
	{
		string choose;			//�Է¹޴� ���� �����
		int cnt = 0;
		cout << "������� �� ������ ���� ���� : ";
		cin >> choose;

		if (choose == "q")
			break;

		for (string a : commons)
		{
			if (a == choose) {
				cnt++;			//������ ������ �ش��б� ������� ���� �� cnt�� ������Ű�� �ݺ����� �������´�.
				break;
			}
		}

		if (cnt == 1)			//cnt�� 1�̶�� ���� ������ ������ �ش��б� ������� �����Ѵٴ� �ǹ��̴�.
		{
			int num = 0;

			for (string a : select)
			{
				if (a == choose) {
					num++;		//choose�� �Է��� ������ �̹� select ���� �ȿ� �����ϴ� ���� �����ϸ� num�� ������Ű�� �ݺ��� �������´�.
					break;
				}
			}

			if (num == 1)	//num�� 1�̶�� ���� select ���� �ȿ� choose�� ���� ���� �����ϴ� ���̴�.
			{
				cout << "�ش������ �̹� ��û�ϼ̽��ϴ�.";
				cout << endl;
			}

			else			//num�� 1�� �ƴ� ��� �� select ���� �ȿ� choose�� ������ ���� ���ٴ� ���̴�. 
			{
				select.push_back(choose);					//select�ȿ� choose�� �߰���Ų��.

				if (choose.find("�ǽ�") != string::npos)		//�ǽ������� ��� ���� ��û�� ������ 2�� �߰��ȴ�.
				{
					current_grades += 2;
				}
				else		//�ǽ������� �ƴ� ��� ���� ��û�� ������ 3�� �߰��ȴ�.
				{
					current_grades += 3;
				}
			}
		}

		else			//cnt�� 1�� �ƴ� ��� �� 0 �ΰ�� ������ ������ �ش� �б� ������� ���ٴ� ���� �ǹ��Ѵ�. 
		{
			cout << "�ش������ �̹��б� ������� �����ϴ�.";
			cout << endl;
		}

		cout << "�� ������û�� ���� ��� : ";
		for (string a : select)
		{
			cout << a << " ";
		}
		cout << endl;
		cout << "���� ��û�� ���� : " << current_grades << endl;
		cout << endl;
	}

	return select;
}

void print_subject(vector<string> select)		//���� ���� ���
{
	cout << endl;
	cout << "=============���� �������� ����=============" << endl<<endl;
	for (string a : select)
		cout << a << " ";
	cout << endl << endl << "=============================================" << endl;
}

void Sub::ask_subject_info(string name) {			//class�� ������ �̿��� ���� ���� �Է�
	cout << "����� : " << name << endl;
	class_name = name;
	cout << "��米�� : ";
	cin >> professor;
	cout << "�ش���� �����ο� : ";
	cin >> students;
	cout << "���� �ݿ� ���� (�⼮, �߰�, �⸻, ����, ���� ���� ��) : ";
	cin >> att >> mid >> fin >> work >> quiz;
	cout << "��� ���ġ (�⼮, �߰�, �⸻, ����, ���� ���� ��) : ";
	cin >> att_exp >> mid_exp >> fin_exp >> work_exp >> quiz_exp;
}

vector<Sub> input_subject_info(vector<string> select, vector<Sub> sub_vec)			//�������� ���� ��ü ���� �Է� ȣ��
{
	for (int i = 0; i < select.size(); i++) {
		Sub s;
		cout << endl << "���� ������ ���� ������ �Է����ּ���" << endl;
		s.ask_subject_info(select.at(i));		//������ �����Ͽ� ���� �Է� �Լ� ȣ��
		cout << endl;
		sub_vec.push_back(s);
	}

	return sub_vec;			//sub_vec�� �����Ͽ� ���� ���� ����
}

vector<Sub> add_subject(vector<string> select, vector<Sub> sub_vec)			//���� �߰� �Լ�
{
	string name;
	Sub s;

	cout << endl << "������� �Է��ϼ��� : ";
	cin >> name;

	s.ask_subject_info(name);		//�Է¹��� ������� ���� ����

	if (current_grades <= limit)	//������ �ʰ����� ���� ���
	{
		sub_vec.push_back(s);			//sub_vec�� ���� ���� �߰�

		cout << endl << "�ԷµǾ����ϴ�." << endl;
	}
	else							//������ �ʰ��� ���
		cout << endl << "���� ���� ������ �ʰ��մϴ�." << endl;

	return sub_vec;			//sub_vec�� �����Ͽ� ���� ���� ����
}

vector<Sub> input_subject_score(vector<Sub> sub_vec, string name)		//��� ���� �Է�
{
	vector<Sub>::iterator iter;
	double score;

	for (iter = sub_vec.begin(); iter != sub_vec.end(); iter++)
	{
		if (iter->getClassName() == name)			//������� class���� ã��
		{
			cout << endl << "�⼮ ���� : ";			//���� �Է¹ޱ� �� �����ϱ�
			cin >> score;
			iter->setScoreAtt(score);
			cout << "�߰���� ���� : ";
			cin >> score;
			iter->setScoreMid(score);
			cout << "�⸻��� ���� : ";
			cin >> score;
			iter->setScoreFin(score);
			cout << "���� ���� : ";
			cin >> score;
			iter->setScoreWork(score);
			cout << "���� ���� : ";
			cin >> score;
			iter->setScoreQuiz(score);
		}
	}

	return sub_vec;
}

string get_subject_score(vector<Sub> sub_vec, string name)		//�Է¹��� ��� ������ ���� ���
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

	select = subject_select(select);			//���� ����

	print_subject(select);						//������ ���� ���

	sub_vec = input_subject_info(select , sub_vec);			//���� ���� �Է�
	
	cout << "==================================" << endl;
	cout << "�����Է��� �Ϸ�Ǿ����ϴ�." << endl;
	cout << "1. ���� ���� ���" << endl;
	cout << "2. ���� �߰�" << endl;
	cout << "3. �������� ���� ��ȸ" << endl;
	cout << "4. ���α׷� ����" << endl;
	cout << "==================================" << endl << endl;
	cout << "���Ͻô� ����� ������ �ּ��� : ";

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
			cout << endl << "������� �Է��ϼ���: ";
			cin >> usrchoice;
			for (iter = sub_vec.begin(); iter != sub_vec.end(); iter++) {			//sub_vec�� ���ۺ��� ������ Ž��
				if (iter->getClassName() == usrchoice) {					//�Է¹��� ������ ���� ���
					sub_vec = input_subject_score(sub_vec, usrchoice);				//������� �Է¹ޱ�
					string score = get_subject_score(sub_vec, usrchoice);					//���� ���ϱ�
					cout << endl << "�ش������ ���� ������ " << score << "�Դϴ�" << endl;
					a = 1;
					break;
				}
			}
			if(a != 1)			//������� ���� ���
				cout << "�������� ���� �����Դϴ�." << endl;
			break;
		case 2:
			if (current_grades == limit)		//�̹� ���� ���� ������ �� �� ���
			{
				cout << "�� �̻� ������ ������ �� �����ϴ�." << endl;
				break;
			}

			cout << "������ ������ ���� : ";
			cin >> point;
			current_grades += point;
			if (current_grades > limit)			//���Ӱ� ������ ������ �ʰ������� �� ���
			{
				cout << "���� ���� ������ �ʰ��մϴ�." << endl;
				current_grades -= point;
				break;
			}

			sub_vec = add_subject(select, sub_vec);					//���� �߰�
			select.push_back(sub_vec.back().getClassName());		//select���� ����� �߰�
			break;
		case 3:
			print_subject(select);
			break;
		}

		cout << endl << "==================================" << endl;
		cout << "���Ͻô� ����� ������ �ּ��� : ";
		cin >> usrc;
	}

	return 0;

}