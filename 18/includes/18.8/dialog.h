#ifndef PRACTICE_PSTU_DIALOG_H
#define PRACTICE_PSTU_DIALOG_H

#include <iostream>
#include "list.h"
#include "event.h"

using namespace std;

class Dialog :
    public List
{
public:
	Dialog(void);
	Dialog(const Dialog&);
	virtual ~Dialog(void);
	virtual void GetEvent(TEvent& event);
	virtual int Execute();
	virtual void HandleEvent(TEvent& event);
	virtual void ClearEvent(TEvent& event);
	int Valid();
	void EndExec();
protected:
	int EndState;
};

Dialog::Dialog(void) : List()
{
    EndState = 0;
}

Dialog::~Dialog(void) {}

void Dialog::GetEvent(TEvent& event)
{
    string OpInt = "+-?/qam";
    string s;
    string param;

    char code;
    cout << "- Создать группу (формат команды: m количество элементов группы).\n"
            "- Добавить элемент в группу (формат команды: +)\n"
            "- Удалить элемент из группы (формат команды: -)\n"
            "- Вывести информацию об элементах группы (формат команды: s)\n"
            "- Вывести информацию о названиях всех элементов группы (формат команды: z)\n"
            "- Конец работы (формат команды q)" << endl;
    cout << "Команда> "; cin >> s;
    code = s[0];
    if (OpInt.find(code) >= 0)
    {
        cout << code << endl;
        event.what = evMessage;
        switch (code)
        {
            case 'm':   event.command = cmMake; break;
            case '+':   event.command = cmAdd; break;
            case '-':   event.command = cmDel; break;
            case '?':   event.command = cmShow; break;
            case '/':   event.command = cmGet; break;
            case 'q':   event.command = cmQuit; break;
        }
        if (s.length() > 1)
        {
            param = s.substr(1, s.length() - 1);

            int A = atoi(param.c_str());
            event.a = A;
        }
    }
    else event.what = evNothing;
}

int Dialog::Execute()
{
    TEvent event; do {
        EndState = 0;
        GetEvent(event);
        HandleEvent(event);
    } while (!Valid()); return EndState;
}

int Dialog::Valid()
{
    if (EndState == 0)
        return 0;
    else
        return 1;
}
void Dialog::ClearEvent(TEvent& event)
{
    event.what = evNothing;
}

void Dialog::EndExec()
{
    EndState = 1;
}

void Dialog::HandleEvent(TEvent& event)
{
    if (event.what == evMessage)
    {
        switch (event.command)
        {
            case cmMake:
                size = event.a;
                cin >> size;
                beg = new Object * [size];
                size = event.a;
                cur = 0;
                ClearEvent(event);
                break;

            case cmAdd:
                Add();
                ClearEvent(event);
                break;

            case cmDel:Del();
                ClearEvent(event);
                break;

            case cmShow:Show();
                ClearEvent(event);
                break;

            case cmQuit:EndExec();
                ClearEvent(event);
                break; default:List::HandleEvent(event);
        };
    };
}

#endif //PRACTICE_PSTU_DIALOG_H