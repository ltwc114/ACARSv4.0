#ifndef ACARSMENUPAGE_H
#define ACARSMENUPAGE_H

#include <Core/ACARSMenu.h>
#include <Core/ACARSSystem.h>

#include <QWidget>
#include <QLabel>
#include <QLineEdit>

class ACARSMenuPage : public QWidget
{

public:

    explicit ACARSMenuPage(QWidget *parent, int iCount, int iNum);

    void setText(QString *Text, QString *Position, ACARSMenu::LINE label=ACARSMenu::MAIN);
    void setText(QString Text, QString Position, ACARSMenu::LINE label=ACARSMenu::MAIN);
    void setTextWithFormat(QString *Text, QString *Position, ACARSMenu::LINE label=ACARSMenu::MAIN, ACARSMenu::COLOR color=ACARSMenu::GREEN);
    void setTextWithFormat(QString Text, QString Position, ACARSMenu::LINE label=ACARSMenu::MAIN, ACARSMenu::COLOR color=ACARSMenu::GREEN);

    void setFilledInput(QString *Position, int iChars, ACARSMenu::COLOR color = ACARSMenu::GREEN);

    QString getText(QString Position);
    QString* getText(QString* Position);

    void setInputLine(QLineEdit *pInputLine);

	void updateFSData(ACARSDataBunk* pNewData);

    virtual bool handleEvent(ACARSSystem *pACARSSys, ACARSActionEvent *pIEvent) = 0;
    virtual bool init() = 0;

    ~ACARSMenuPage(){}

    int getLSKIndex(QString sEntry);
protected:

    void resetEntry(QString sEntry);
	bool changedEntry(QString sEntry);

    QLabel* PlaceHolder;
    QLabel* PageIdentifier;
    QLabel* MainLabels[12];
    QLabel* SecondLabels[12];

	QString mDefaultEntries[12];

    QLineEdit* m_pInputLine;

    QString getColorString(ACARSMenu::COLOR color);

    int m_iPageCount;
    int m_iPageNum;

    static const char* pCharInputPlaceholder;

	ACARSDataBunk* m_pFSData;
	ACARSSystem* m_pACARSSys;

};


#endif // ACARSMENUPAGE_H
