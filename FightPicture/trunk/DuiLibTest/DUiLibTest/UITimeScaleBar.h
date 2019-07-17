#ifndef __UI_TIME_SCALE_BAR_H__
#define __UI_TIME_SCALE_BAR_H__

#define SECONDES_PER_DAY	60*60*24

typedef struct tagTime
{
	byte	byHour;
	byte	byMin;
	byte	bySec;
	//byte    wMSec; // ΢��
}TTime;

typedef struct tagTimePeriod
{
	TTime tStart;
	TTime tEnd;
}TTimePeriod;

struct TIntPeriod
{
	LONG nStart;
	LONG nEnd;
};

TTime Int2TTime(int nSecs);
int TTime2Int(TTime t);

class CTimeScaleBarUI : public CControlUI
{
public:
	CTimeScaleBarUI();
	~CTimeScaleBarUI();

public:
	LPCTSTR GetClass() const;
	LPVOID GetInterface(LPCTSTR pstrName);
	
	void SetAttribute(LPCTSTR pstrName, LPCTSTR pstrValue);
	void DoEvent(TEventUI& event);
	bool DoPaint(HDC hDC, const RECT& rcPaint, CControlUI* pStopControl);

public:
	// �������ݽӿ�
	void ResetPeriod() {m_vecPeriod.clear();Invalidate();}
	bool AddPeriod(const TTimePeriod& tTimePeriod);
	int	 GetPeriodCnt() {return m_vecPeriod.size();}
	bool GetPeriodByIndex(int index, TTimePeriod& tPeriod);

protected:
	bool PtInValidRect(POINT pt);
	bool PtInPeriod(POINT pt);
	bool GetXPosByTime(int nSecs, int& xPos);
	int GetTimeByXPos(int x);
	void AddPeriod(int nStart, int nEnd);
	bool GetPeriodByXPOS(int x, TIntPeriod& tPeriod);
	void RemovePeriodByXPos(int x);

	// ���ż���,nSecsΪ���Ŵ�Ϊ����С
	void Zoom(int nCurTime, int nSecs);

protected:
	// ��������
	int m_nSideBlank; // ���߿հ׾���
	DWORD m_dwScaleLineColor; // �̶�����ɫ
	DWORD m_dwScaleTextColor; // �̶���������ɫ
	DWORD m_dwTimePeriodColor; // ʱ�����ɫ
	DWORD m_dwTimePeriodBorderColor; // ʱ��α߿���ɫ
	int m_nMaxPeriod; // ����ѡ���ʱ�����
	int m_nPrecision; // ����

	int m_nStarttime; // ����ʾ�Ŀ�ʼʱ��ֵ(��λ��s)
	int m_nEndtime; // ĩ�˱�ʾ�Ľ���ʱ��ֵ(��λ��s)
	vector<TIntPeriod> m_vecPeriod; // ��¼ʱ�����Ϣ

	bool m_bLBtnDown;
	int m_nTimeLBtnDown;
	TIntPeriod m_tValidPeriodLBtnDown;
	bool m_bLBtnDrag;
	int m_nTimeMouseMove;
};

#endif // __UI_TIME_SCALE_BAR_H__