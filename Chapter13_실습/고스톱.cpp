/*
    Cpp �ǽ� : ����

    ����
    0. 2�ο����� ����
    1. ���� ī�� ������ �������� ���� ������ �ι�� ����� ��Ģ�� ������� ������ �ʿ��ϰ�
       �ѹ��� �ϳ��� ī�带 ���� ��Ģ�� ���ܰ� ���� ����
    2. ������ �Ƿ� ���Ǵ� ����, �ǿ� ��¥�� �������� �� �� �ִ� ī��, ���ʽ� ī��� ����
    3. �ǹ�, ���� �� ������ ������ ����� ��Ģ�� ����
    4. �÷��̾�� ����, �ϱ�, ��� ī��� �������ְ� �������� ī��� ???�� ǥ��
    5. �����ʿ� �� �÷��̾ ���� ī��� ����, �� Ƚ���� ǥ�õȴ�.
    6. �ܼ�ȯ�濡���� ���콺�� �� �� ��� ����Ű�� �и� ����.
    7. Ŭ�������� //// �� �ּ� �߰�, �������� //�� �ּ� �߰�
*/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <conio.h>
#include "cursor.h" // ȭ�� ��ü�� ����ϰ� õõ�� �����ϱ����� gotoxy, delay �Լ�
#include <string.h>
#include <assert.h>
#include <iostream>
using namespace std;

const int MaxCard = 48;    // ȭ���� ����
const int CardGap = 4;     // ī�� ���� ����(�ϳ��� ī�带 �� ���� ���̷� ����ϰ� ���� �ϳ��� ���ؼ� 4ĭ)
const int Speed = 1000;        // ī�带 ���ų� �޼����� ����Ҷ� ����� �ð� => ��ü���� ���Ӽӵ� ����
const int PromptSpeed = 2000;  // ��ȭ�� ���涧���� �������� �帧�� �޼����� Ȯ���� �ð��� Ȯ���Ǿ���.


//// ȭ�� ������ ǥ���ϴ� Ŭ����
struct SCard
{
    char Name[4];
    SCard() { Name[0] = 0; }
    SCard(const char* pName)
    {
        strcpy(this->Name, pName);
    }

    int GetNumber() const  // ȭ���� ����
    {
        if (isdigit(Name[0])) return Name[0] - '0';
        if (Name[0] == 'J') return 10;                      // 10�� �̻��� ī�带 ��, ��, ������ �Ҹ��µ� 1����Ʈ ǥ�������� J, B, D�� ǥ��
        if (Name[0] == 'D') return 11;
        return 12;
    }

    int GetKind() const   // ȭ���� ����
    {
        if (strcmp(Name + 1, "��") == 0) return 0;          // ī���� ������ ��, ��, ��, �� 4������ ����
        else if (strcmp(Name + 1, "��") == 0) return 1;
        else if (strcmp(Name + 1, "��") == 0) return 2;
        else if (strcmp(Name + 1, "��") == 0) return 3;
        else return 4;
    }

    friend ostream& operator <<(ostream& c, const SCard& C) // << ������ ����, Name ����� cout�� ���
    {
        return c << C.Name;
    }

    bool operator ==(const SCard& Other) const              // == ������ ����, �� ī�尡 ������ ����. �̸��� ��ġ�ϸ� ���� ī����.
    {
        return (strcmp(Name, Other.Name) == 0);
    }

    bool operator <(const SCard& Other) const               // < ������ ����, �� ī���� ��Ҹ� ��.(1���� ����, ���ڰ� ������ ��, ��, ��, �� ������ ������ �ű�)
    {
        if (GetNumber() < Other.GetNumber()) return true;
        if (GetNumber() > Other.GetNumber()) return false;
        if (GetKind() < Other.GetKind()) return true;
        return false;
    }
};


// ȭ���� �ʱ� ī�� ���
SCard HwaToo[MaxCard] = {
    "1��","1��","1��","1��","2��","2��","2��","2��","3��","3��","3��","3��",
    "4��","4��","4��","4��","5��","5��","5��","5��","6��","6��","6��","6��",
    "7��","7��","7��","7��","8��","8��","8��","8��","9��","9��","9��","9��",
    "J��","J��","J��","J��","D��","D��","D��","D��","B��","B��","B��","B��"
};


//// ī���� ������ �����ϴ� Ŭ����
//// ����, ����, �˻� ���� �⺻���� ��� ����
//// �� Ŭ������ ���ӿ� �����ϴ� ī�� ������ ���� �θ�������.
class CCardSet
{
protected:
    SCard Card[MaxCard];
    int Num;                 // ���տ� ���Ե� ī���� ���� ����(����, �����Ǹ鼭 ����)
    const int sx, sy;        // ī�� ������ ȭ��� ��ǥ�̸鼭 ��� ��ġ�� ������ ���� ���⶧���� ���ȭ
    CCardSet(int asx, int asy) : sx(asx), sy(asy) { Num = 0; }

public:
    int GetNum() 
    { 
        return Num; 
    }    
    SCard GetCard(int idx) 
    { 
        return Card[idx]; 
    }
    void Reset() 
    {
        for (int i = 0; i < MaxCard; i++) Card[i].Name[0] = 0;
        Num = 0;
    }

    void InsertCard(SCard C);              // ī������Լ�
    SCard RemoveCard(int idx);             // ������ ÷���� ī�带 �����ϰ� �ش� ī�带 ����(�տ��� ī�� ���ų� ��ũ���� ī�带 �������� ȣ��)
    int FindSameCard(SCard C, int* pSame); // C�� ��ġ�ϴ� ī�带 �����ϴ� �Լ�
    int FindFirstCard(const char* pName);
    int GetMaxSeries();
};

// ī�� ���� �Լ�
void CCardSet::InsertCard(SCard C)        
{
    int i;

    if (C.Name[0] == 0) return;
    for (i = 0; i < Num; i++) 
    {
        if (C < Card[i]) break;
    }
    memmove(&Card[i + 1], &Card[i], sizeof(SCard) * (Num - i));
    Card[i] = C;
    Num++;
}

SCard CCardSet::RemoveCard(int idx) 
{
    assert(idx < Num);
    SCard C = Card[idx];
    memmove(&Card[idx], &Card[idx + 1], sizeof(SCard) * (Num - idx - 1));
    Num--;
    return C;
}

int CCardSet::FindSameCard(SCard C, int* pSame) 
{
    int i, num;
    int* p = pSame;

    for (i = 0, num = 0; i < Num; i++) 
    {
        if (Card[i].GetNumber() == C.GetNumber()) 
        {
            num++;
            *p++ = i;
        }
    }
    *p = -1;
    return num;
}

int CCardSet::FindFirstCard(const char* pName) 
{
    int i;

    for (i = 0; i < Num; i++) 
    {
        if (strstr(Card[i].Name, pName) != NULL) 
        {
            return i;
        }
    }
    return -1;
}

// �Ѳ����� ���� ī�尡 �������� �����ϴ� �Լ�
int CCardSet::GetMaxSeries()   
{
    int i, n, m, old = -1;

    for (i = 0, n = 1, m = 1; i < Num; i++) 
    {
        if (old == Card[i].GetNumber()) 
        {
            n++;
            m = max(n, m);
        }
        else 
        {
            n = 1;
            old = Card[i].GetNumber();
        }
    }
    return m;
}

//// ��� �߾ӿ� ī�带 �׾� ���� ��
class CDeck : public CCardSet  // ī���� �����̹Ƿ� CCardSet���� ��ӹ���
{
public:
    CDeck(int asx, int asy) : CCardSet(asx, asy) { ; }
    void Shuffle()          // ī�带 �������� ����(�����Լ����)
    {
        int i, n;
        for (i = 0; i < MaxCard; i++) 
        {
            do 
            {
                n = random(MaxCard);
            } while (Card[n].Name[0] != NULL);

            Card[n] = HwaToo[i];    // ȭ��(1��, 1�� ���� �̸��� �̳������ִ� �迭)�� �������� Card�迭�� ��
            Num++;
        }
    }
    SCard Pop() { return RemoveCard(Num - 1); } // ī�带 ���������� ���徿 �÷��̾�� �����ִ� �Լ�
    bool IsEmpty() { return Num == 0; }         // ī�尡 0���� �����Ͽ� ���ӳ����� ������.
    bool IsNotLast() { return Num > 1; }        // ������������ ����
    void Draw(bool bFlip)                       // ȭ�鿡 ���� �׸��� �Լ�. ???�� ����ϰ� ������ �� ���������� ���� ����ī������ ������
    {
        gotoxy(sx, sy);
        cout << "??? " << (bFlip ? Card[Num - 1].Name : "   ");  // bFlip�μ��� ���� ������ ������ �����ٰ������� ������
    }
};



//// ������ �ϴ� �÷��̾�
class CPlayer : public CCardSet
{
public:
    CPlayer(int asx, int asy) : CCardSet(asx, asy) { ; }

    // �÷��̾��� �и� �׸��� �Լ� => �տ� �� ī�带 ������� ȭ�鿡 ����.
    // �ڱ������϶��� � ī�带 ���� �Է¹ޱ����� �� �Ʒ��ʿ� �Ϸ� ��ȣ�� ���
    // 1�� 2�� 2�� 5�� 5��         // ���� �̷��Ժ��̴ٰ�
    // [1] [2] [3] [4] [5]         // �ڱ����ʵǸ� ��ȣ�� �����Ե�.(�̶� ���ڸ� �Է��ϸ� �� ī�带 ���°���)
    void Draw(bool MyTurn)  
    {
        int i, x;
        for (i = 0, x = sx; i < Num; i++, x += CardGap) 
        {
            gotoxy(x, sy);
            cout << Card[i];
            if (MyTurn) 
            {
                gotoxy(x, sy + 1);
                cout << '[' << i + 1 << ']';
            }
        }
    }
};


// ������ ����Ǵ� ��� : ī�带 �����ֱ⸸�ϸ�Ǽ� ī�带 �� �ʿ�� ���� => Draw�Լ��� �״�� ȣ���ϵ� Myturn �μ��� �׻� false��.
// ��� ��ġ�ϴ� ī�尡 �����϶� � ī�带 ������ ���ù޾ƾ���.
class CBlanket : public CPlayer
{
public:
    CBlanket(int asx, int asy) : CPlayer(asx, asy) { ; }
    void Draw() {
        CPlayer::Draw(false);
    }


    // DrawSelNum �Լ�
    //                 [1] [2]      // ī��´µ� ��ġ�ϴ� ī�尡 2���̸� �̷��� ��ȣ�� ���;���(1, 2 �߿� Ű�����Է����� �������� ����)
    // 1�� 2�� 2�� 5�� 8�� 8��
    void DrawSelNum(int* pSame) 
    {
        int n;
        int* p;
        for (n = 1, p = pSame; *p != -1; p++, n++) 
        {
            gotoxy(sx + *p * CardGap, sy - 1);
            cout << '[' << n << ']';
        }
    }


    // DrawTempCard �Լ�
    // 1�� 2�� 2�� 5�� 8��
    //             5��          // ī��´µ� ��ġ�ϴ� ī�尡������ �̷��� ǥ���� 
    void DrawTempCard(int idx, SCard C) 
    {
        gotoxy(sx + idx * CardGap, sy + 1);
        cout << C;
    }
};



//// �÷��̾ ���� ī���� ����
class CPlayerPae : public CCardSet
{
private:
    int nGo;            // �� Ƚ���� ���ܳ���(1���� �����ϸ鼭 �����ϴ� ���� ����)
                       
public:
    int OldScore;       // 6������ �ʱ�ȭ, �°�� 7�� �̻���� ���鰡��.
    int bShake;
    CPlayerPae(int asx, int asy) : CCardSet(asx, asy) { OldScore = 6; nGo = 0; bShake = false; }
    void Reset() { CCardSet::Reset(); OldScore = 6; nGo = 0; bShake = false; }
    int GetGo() { return nGo; }
    void IncreaseGo() { nGo++; }
    void Draw();                        // ���� �и� ȭ�鿡 ���
    int RemovePee(int n, SCard* pCard); // ������ �� ���� �Ѳ����� �Ͼ��������� �� ������ �����Ͽ� ���濡�� �ִ� �Լ�
                                        // RemovePee���� ���ϵǴ� ī��� ������ ���� �п� ���Ե�.  
    int CalcScore();  // ���� ��Ģ��� ���� ���. 
                      // �� ���������� ���� �̻��� ���� 3, 4, 15��.    ���� ���Ե� 3���� 2��.
                      // �ʰ� ���� �ټ� ����� 1������ ���
                      // û��, �ʴ�, ȫ���� �� 3��, ������ 5��
};


// ���� �и� ȭ�鿡 ���
void CPlayerPae::Draw() 
{
    int i, kind;
    int x[4] = { sx,sx,sx,sx }, py = sy + 3;

    for (i = 0; i < Num; i++) 
    {
        kind = Card[i].GetKind();
        if (kind < 3) 
        {
            gotoxy(x[kind], sy + kind);
            x[kind] += CardGap;
        }
        else 
        {
            gotoxy(x[3], py);
            x[3] += CardGap;
            if (x[3] > 75) 
            {
                x[3] = sx;
                py++;
            }
        }
        cout << Card[i];
    }

    // ó���а� 3���̻��϶� �������� ȭ�鿡 �����ٴ� ǥ���صα�
    gotoxy(sx + 20, sy);
    cout << "����:" << CalcScore() << "��, " << nGo << "�� "
        << (bShake ? "���" : "");
}


// ������ 3���� �Ѳ����� �԰ų� �Ͼ��� ������ �� ������ �����Ͽ� ���濡�� �ٶ�
// RemovePee�� �����ϴ� ī��� ������ ���� �п� ���Ե�.
int CPlayerPae::RemovePee(int n, SCard* pCard) 
{
    int ns = 0;
    int np = 0; 
    int tp;
    int i, idx, num = 0;
    SCard* p = pCard;

    for (i = 0; i < Num; i++) 
    {
        if (Card[i].GetKind() == 3) ns++;
        if (Card[i].GetKind() == 4) np++;
    }
    tp = ns + np;
    if (tp == 0) return 0;

    switch (n) 
    {
    case 1:
        if (np != 0) 
        {
            *p++ = RemoveCard(FindFirstCard("��"));
            return 1;
        }
        else 
        {
            *p++ = RemoveCard(FindFirstCard("��"));
            return 1;
        }
        break;

    case 2:
        if (ns != 0) 
        {
            *p = RemoveCard(FindFirstCard("��"));
            return 1;
        }
        else 
        {
            *p++ = RemoveCard(FindFirstCard("��"));
            num = 1;
            if (np >= 2) 
            {
                *p++ = RemoveCard(FindFirstCard("��"));
                num = 2;
            }
            return num;
        }

    case 3:
        i = RemovePee(2, p);
        p += i;
        idx = RemovePee(1, p);
        return i + idx;

    default:
        return 0;
    }
}

// ���� ��Ģ��� ������ ���
int CPlayerPae::CalcScore() 
{
    int i, kind, n[4] = { 0, };
    int NewScore;
    static int gscore[] = { 0,0,0,3,4,15 };

    for (i = 0; i < Num; i++) 
    {
        kind = Card[i].GetKind();
        if (kind == 3) n[kind]++;
        if (kind >= 3) kind = 3;
        n[kind]++;
    }

    NewScore = gscore[n[0]];

    if (n[0] == 3 && FindFirstCard("B��") != -1) NewScore--;
    if (n[1] >= 5) NewScore += (n[1] - 4);
    if (n[2] >= 5) NewScore += (n[2] - 4);
    if (n[3] >= 10) NewScore += (n[3] - 9);
    if (FindFirstCard("8��") != -1 && FindFirstCard("5��") != -1 && FindFirstCard("2��") != -1) NewScore += 5;
    if (FindFirstCard("1��") != -1 && FindFirstCard("2��") != -1 && FindFirstCard("3��") != -1) NewScore += 3;
    if (FindFirstCard("4��") != -1 && FindFirstCard("5��") != -1 && FindFirstCard("7��") != -1) NewScore += 3;
    if (FindFirstCard("9��") != -1 && FindFirstCard("J��") != -1 && FindFirstCard("6��") != -1) NewScore += 3;

    return NewScore;
}




///////////////////////////////////////////////�������� Ŭ���� ����////////////////////////////////////////////////////////////////////



// �Լ� ����
void Initialize();
void DrawScreen();
void OutPrompt(const char* Mes, int Wait = 0);
int InputInt(const char* Mes, int start, int end);


// ���� ����
CDeck Deck(18, 9);
CPlayer South(5, 20), North(5, 1);  // �÷��̾�(����, �ϱ�)
CBlanket Blanket(5, 12);
CPlayerPae SouthPae(40, 14), NorthPae(40, 4);
bool SouthTurn;       // ���� ���� ī�带 �� �������� ����� ����



void main()
{
    int i, ch;
    int arSame[4], SameNum;
    char Mes[256];
    CPlayer* Turn;
    CPlayerPae* TurnPae, * OtherPae;
    int UserIdx, UserSel, DeckSel;
    SCard UserCard, DeckCard;
    bool UserTriple;           // �÷��̾ ī�带 �´µ� ���β� + ����� 3��, �� 4���� �Ծ����� flag
    bool DeckTriple;           // ������ ��ũ�� ī�带 �������µ� 3���� ��ġ�Ҷ��� üũ�ϴ� flag
    int nSnatch;
    int NewScore;
    SCard arPee[3];
    int nPee;
    CPlayer* LastGo = NULL;

    randomize();

    /*for (int k = 0; k < 1000; k++) {    // �ڵ� �׽�Ʈ. main�Լ� �ǹؿ� for�� �ݴ� �߰�ȣ( '}')����.
        srand(k);*/


    Initialize();
    DrawScreen();    // �� ��ü�� ȭ�鿡 �׸��� ����


    // ó�� ī���߿� 3���� ������ ��鲫�� ������ ��� (����, �ϱ� ���� 1����)
    if (South.GetMaxSeries() == 3)     
    {
        ch = InputInt("���� ī�尡 �� ���Դϴ�. (1:����, 2:�׳� �ϱ�) ", 1, 2);
        if (ch == 1) SouthPae.bShake = true;
    }

    if (North.GetMaxSeries() == 3)
    {
        ch = InputInt("���� ī�尡 �� ���Դϴ�. (1:����, 2:�׳� �ϱ�) ", 1, 2);
        if (ch == 1) NorthPae.bShake = true;
    }

    for (SouthTurn = true; !Deck.IsEmpty(); SouthTurn = !SouthTurn)  // ������ ��, ���� 0���϶�����, ������ ���� ������ ���� �ƴҶ�(= �ϱ��� ��)
    {
        DrawScreen(); 

        // ������ ������ ����
        if (SouthTurn)     // ������ ���϶�
        {
            Turn = &South;
            TurnPae = &SouthPae;
            OtherPae = &NorthPae;
        }
        else               // �ϱ��� ���϶�
        {
            Turn = &North;
            TurnPae = &NorthPae;
            OtherPae = &SouthPae;
        }

        // �����ִ� ī���߿� �� ������ ���
        sprintf(Mes, "���� ���� ȭ���� �����ϼ���(1~%d,0:����) ", Turn->GetNum());
        ch = InputInt(Mes, 0, Turn->GetNum());

        if (ch == 0) 
        {
            // ���� ���ǹ�
            if (InputInt("���� �����̴ϱ�?(0:��,1:�ƴϿ�)", 0, 1) == 0)  
                return;       // 0 ������ ����
            else
                continue;     // 1 ������ �׳� ��� ����
        }

        // �÷��̾ ī�带 ���� ����.
        UserTriple = DeckTriple = false;
        UserIdx = ch - 1;
        UserCard = Turn->GetCard(UserIdx);
        SameNum = Blanket.FindSameCard(UserCard, arSame);  // �÷��̾ �� ī��� ����� ī���� ��ġ ������ FindSameCard�� ���ؼ� SameNum�� ����

        // 
        switch (SameNum) 
        {
        case 0:                // ��ġ�ϴ� ī�尡 ���°��
            UserSel = -1;
            Blanket.InsertCard(Turn->RemoveCard(UserIdx));
            DrawScreen();
            break;

        case 1:                // �ϳ��� ��ġ�ϴ� ��� => �� ī�带 ����, �ٵ� �������� ���� ���� �����ϱ� �̵����ϸ�ȵ�.
            UserSel = arSame[0];
            break;

        case 2:                // �� ���� ��ġ�ϴ� ��� => �� �� ����� ������ �����ϰ� �÷��̾ ������ ī�带 UserSel�� ����
            if (Blanket.GetCard(arSame[0]) == Blanket.GetCard(arSame[1])) 
            {
                UserSel = arSame[0];  
            }
            else 
            {
                // ��ġ�ϴ� ī�� ����� arSame�� ��� ����� DrawSelNum�� ȣ��.
                // ������� Ű �Է����޾� UserSel�� ����.
                Blanket.DrawSelNum(arSame);
                sprintf(Mes, "� ī�带 �����Ͻðڽ��ϱ�?(1~%d)", SameNum); 
                UserSel = arSame[InputInt(Mes, 1, SameNum) - 1];
            }
            break;


            // �ΰ��� ��ġ�ϴ� ��� ( 2���� ����� ��)
            /*
             (���)      1�� (4�� 4��) 9�� B��                  1�� (4�� 4��) 9�� B��
                   
                          ������ �ϴ� ���                       ���� �ʿ���� ��� => �� �߿� ���Ե� �Ȱ��⶧���� �ʿ����.

                                 
                                              (�÷��̾�ī��) 4��
            */


        case 3:                  // �� ���� ��ġ�ϴ� ��� => ó������ 3���� ��Ȱų� �Ѱ��� �Դ� ��� => 4���� ī�带 �� �԰� ������ �Ǹ� �ϳ� �����
            UserSel = arSame[1]; // 3�� �߿� ��� ī�带 ����
            UserTriple = true;   // 3���� �������� flag�� true�� ����
            break;
        }

        if (UserSel != -1) 
        {
            Blanket.DrawTempCard(UserSel, UserCard);
        }
        delay(Speed);


        // ��ũ���� ������ �����´�.
        Deck.Draw(true);
        delay(Speed);
        
        DeckCard = Deck.Pop();  // Pop�Լ��� ��ũ�� ���� �����ִ� ī�带 ������ DeckCard�� ����

        SameNum = Blanket.FindSameCard(DeckCard, arSame);  // 

        
        // ��ũ���� ������ ī��� ����� ī�尡 ��ġ�ϴ� ������ ���� ���� ������ ������
        switch (SameNum) 
        {
        case 0:                  // ��ġ�ϴ� ī�尡 ���� ��� => �÷��̾ �� ī��� ��� ��信 ���Ե�����,
                                                             // ��ũ���� ������ ī��� �ٷ� �������� ���� �÷��̾��� ī�尡 ó���ɶ� ���� �����.
            DeckSel = -1;   // ������ ����...
            break;

        case 1:                  // �ϳ��� ��ġ�ϴ� ��� 
            DeckSel = arSame[0];         // DeckSel�� ��ġ�� ī�� ÷�ڸ� ����
            if (DeckSel == UserSel) 
            {
                if (Deck.IsNotLast())    // ��ũ�� ī�带 ���������� �÷��̾ �� ī��� ��ũ�� ī�尡 ��ġ�ϸ� �մٰ� ǥ��.
                {
                    Blanket.InsertCard(DeckCard);
                    Blanket.InsertCard(Turn->RemoveCard(UserIdx));
                    OutPrompt("�ս��ϴ�.", PromptSpeed);
                    continue;            // ī�带 �������� ���ϰ� ��� ī�带 ��信 ��ä�� ������ ��� �����.
                }
                else                     // ������ �ǿ��� �δ°� ������ -1�� �����ؼ� ����ڰ� �� ī�带 �״�� ����������.
                {
                    DeckSel = -1;
                }
            }
            break;

        case 2:                  // �� ���� ��ġ�ϴ� ��� => �÷��̾ ī�带 �� ���ó�� � ī�带 ������ �÷��̾�� ����.
            if (UserSel == arSame[0])     
            {
                DeckSel = arSame[1];
            }
            else if (UserSel == arSame[1]) 
            {
                DeckSel = arSame[0];
            }
            else 
            {
                if (Blanket.GetCard(arSame[0]) == Blanket.GetCard(arSame[1])) // ���� �������� ���� �ʿ���� ���� �ϳ��� ������
                {
                    DeckSel = arSame[0];
                }
                else 
                {
                    Blanket.DrawSelNum(arSame); 
                    sprintf(Mes, "� ī�带 �����Ͻðڽ��ϱ�?(1~%d)", SameNum);
                    DeckSel = arSame[InputInt(Mes, 1, SameNum) - 1];
                }
            }
            break;

        case 3:               // �� ���� ��ġ�ϴ� ��� => ��� ī�带 �� ������.
            DeckSel = arSame[1];   // DeckSel�� ��� ī�带 ����
            DeckTriple = true;     // DeckTriple flag�� true ��������.
            break;
        }

        if (DeckSel != -1) 
        {
            Blanket.DrawTempCard(DeckSel, DeckCard);
        }
        Deck.Draw(false);
        delay(Speed);


        // ��ġ�ϴ� ī�带 �����ö� => �� ���� ���� ���� ���� ������(UserTriple�� flag�� ���)
        if (UserSel != -1)
        {
            if (UserTriple)   // ������ �Ծ�����
            {
                for (i = 0; i < 3; i++) 
                {
                    TurnPae->InsertCard(Blanket.RemoveCard(UserSel - 1));
                }
            } 
            else  
            {
                TurnPae->InsertCard(Blanket.RemoveCard(UserSel));
            }
            TurnPae->InsertCard(Turn->RemoveCard(UserIdx));
            if (DeckSel != -1 && DeckSel > UserSel) 
            {
                DeckSel -= (UserTriple ? 3 : 1);
            }
        }
        if (DeckSel != -1) 
        {
            if (DeckTriple) 
            {
                for (i = 0; i < 3; i++) 
                {
                    TurnPae->InsertCard(Blanket.RemoveCard(DeckSel - 1));
                }
            }
            else 
            {
                TurnPae->InsertCard(Blanket.RemoveCard(DeckSel));
            }
            TurnPae->InsertCard(DeckCard);
        }
        else 
        {
            Blanket.InsertCard(DeckCard);
        }

        // ��, ����, �Ͼ��� ������ �����ϰ� ������ �Ǹ� ���´�.
        nSnatch = 0;
        if (Deck.IsNotLast()) 
        {
            if (UserSel == -1 && SameNum == 1 && DeckCard.GetNumber() == UserCard.GetNumber()) 
            {
                nSnatch++;
                OutPrompt("���Դϴ�.", PromptSpeed);
            }
            if (UserSel != -1 && SameNum == 2 && DeckCard.GetNumber() == UserCard.GetNumber())
            {
                nSnatch++;
                OutPrompt("�����Դϴ�.", PromptSpeed);
            }
            if (Blanket.GetNum() == 0) 
            {
                nSnatch++;
                OutPrompt("�Ͼ����Դϴ�.", PromptSpeed);
            }
            if (UserTriple || DeckTriple) 
            {
                OutPrompt("�Ѳ����� �� ���� �Ծ����ϴ�.", PromptSpeed);
                nSnatch += UserTriple + DeckTriple;
            }
        }

        nPee = OtherPae->RemovePee(nSnatch, arPee);
        for (i = 0; i < nPee; i++) 
        {
            TurnPae->InsertCard(arPee[i]);
        }


        // ������ ����ϰ� ��, ���� ���θ� �����Ѵ�.
        NewScore = TurnPae->CalcScore();
        if (Deck.IsNotLast() && NewScore > TurnPae->OldScore) 
        {
            DrawScreen();
            if (InputInt("�߰� ������ ȹ���߽��ϴ�.(0:����, 1:���)", 0, 1) == 1) 
            {
                TurnPae->OldScore = NewScore;
                TurnPae->IncreaseGo();
                LastGo = Turn;
            }
            else 
            {
                break;
            }
        }
    }

    DrawScreen();

    // �ºο� �ǹ�, ����, ���� ���� ����
    bool SouthWin;
    int SouthScore, NorthScore;
    int TurnPee = 0;
    int TurnLight = 0; 
    int OtherPee = 0;
    int OtherLight = 0;

    if (Deck.IsEmpty())      // ��ũ�� 0���� ������
    {
        if (LastGo != NULL)  // ���� �� �� �Ѹ��� ����϶��� ����� ����� ������ �й�
        {
            SouthWin = (LastGo == &North);
        }
        else                 // ����� ������ ������ ���
        {
            SouthScore = SouthPae.CalcScore();
            NorthScore = NorthPae.CalcScore();
            if (SouthScore < 7 && NorthScore < 7) 
            {
                OutPrompt("���� ��� �⺻ ������ ���� ���� �����ϴ�.");
                return;
            }
            SouthWin = (SouthScore > NorthScore);
        }
    }
    else 
    {
        SouthWin = SouthTurn;
    }

    sprintf(Mes, "%s���� �̰���ϴ�. ", SouthWin ? "��" : "��");

    if (SouthWin)  // ������ �̰�����
    {
        TurnPae = &SouthPae;
        OtherPae = &NorthPae;
    }
    else           // �ϱ��� �̰�����
    {
        TurnPae = &NorthPae;
        OtherPae = &SouthPae;
    }
    for (i = 0; i < TurnPae->GetNum(); i++) 
    {
        if (TurnPae->GetCard(i).GetKind() >= 3) TurnPee++;
        if (TurnPae->GetCard(i).GetKind() == 0) TurnLight++;
    }
    for (i = 0; i < OtherPae->GetNum(); i++) 
    {
        if (OtherPae->GetCard(i).GetKind() >= 3) OtherPee++;
        if (OtherPae->GetCard(i).GetKind() == 0) OtherLight++;
    }

    if (TurnPee >= 10 && OtherPee < 5 && OtherPee != 0)  // ���� �ǰ� �ټ� �� �̸��϶�
    {
        strcat(Mes, "������ �ǹ��Դϴ�. ");
    }
    if (TurnLight >= 3 && OtherLight == 0)               // ������ ���� ���Ծ�����
    {
        strcat(Mes, "������ �����Դϴ�. ");
    }
    if (OtherPae->GetGo() != 0)                          // ������ �������� �߰� ������ ���Ծ�����
    {
        strcat(Mes, "������ �����Դϴ�. ");
    }
    OutPrompt(Mes);

    /*
    // �׽�Ʈ �Ҷ� ����ϴ� �ڵ�
    gotoxy(40, 22);
    if (Blanket.GetNum() != 0) 
    {
        printf("%d �������� �̻��� ����", k);
        _getch();
    }
    else 
    {
        printf("%d�� �׽�Ʈ �Ϸ�", k);
        delay(500);
    }
    SouthPae.Reset();
    NorthPae.Reset();
    // }

    */

}


/////////////////////////////////////////////�ؿ� ���� ����� �Լ�////////////////////////////////////////


/// <summary>
/// ���� �и� �������� ���� ī�带 �ʱ�ȭ�ϴ� �Լ� => �÷��̾����� ī�� 10�� ������ ��信 8�� ī�带 ����
/// </summary>
void Initialize()
{
    int i;

    for (;;) {
        Deck.Reset();
        South.Reset();
        North.Reset();
        Blanket.Reset();
        Deck.Shuffle();
        for (i = 0; i < 10; i++) 
        {
            South.InsertCard(Deck.Pop());
            North.InsertCard(Deck.Pop());
            if (i < 8) Blanket.InsertCard(Deck.Pop());
        }

        // 4���� ���� �а� ������ Reset�Լ��� ������ ���� �ٽ� ����
        if (South.GetMaxSeries() != 4 && North.GetMaxSeries() != 4 && Blanket.GetMaxSeries() != 4)
            break;
    }
}

/// <summary>
/// ȭ���� ����� ��� ��ü�� Draw �Լ��� ���ʴ�� ȣ���ϴ� �Լ�
/// </summary>
void DrawScreen()
{
    clrscr();
    South.Draw(SouthTurn);
    North.Draw(!SouthTurn);
    Blanket.Draw();
    Deck.Draw(false);
    SouthPae.Draw();
    NorthPae.Draw();
}

/// <summary>
/// ����ڿ��� ���� ���¸� �˷��ְų� ���� �ൿ�� ������ �޼��� ��� �Լ�
/// </summary>
void OutPrompt(const char* Mes, int Wait/*=0*/)
{
    gotoxy(5, 23);
    for (int i = 5; i < 79; i++) { cout << ' '; }
    gotoxy(5, 23);
    cout << Mes;
    delay(Wait);
}

/// <summary>
/// ������ ������ ���� �ϳ��� �Է¹޴� �Լ�(Ű������ ����Ű�� ����, ���� 10��� ���ĺ� a�� ����)
/// </summary>
int InputInt(const char* Mes, int start, int end)
{
    int ch;

    OutPrompt(Mes);
    for (;;) {
        ch = tolower(_getch());
        if (ch == 0xE0 || ch == 0)
        {
            ch = _getch();
            continue;
        }
        if (!(isdigit(ch) || ch == 'a')) continue;
        if (ch == 'a') ch = 10; else ch = ch - '0';
        if (ch >= start && ch <= end) 
        {
            return ch;
        }
        OutPrompt("��ȿ�� ��ȣ�Դϴ�. ������ ������ �°� �ٽ� �Է��� �ּ���.");
    }
}