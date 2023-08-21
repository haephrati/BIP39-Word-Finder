// Bip39FinderDlg.h : header file
//

#pragma once
#include "afxwin.h"

// CBip39FinderDlg dialog
class CBip39FinderDlg : public CDialogEx
{
	// Construction
public:
	CBip39FinderDlg(CWnd* pParent = NULL);	// standard constructor

	// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum {
		IDD = IDD_BIP39FINDER_DIALOG
	};
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support

	// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	virtual BOOL OnInitDialog();
	afx_msg void OnPaint();
	afx_msg LRESULT OnPostInit(WPARAM wParam, LPARAM lParam);
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnTimer(UINT_PTR nIDEvent);


	DECLARE_MESSAGE_MAP()

public:
	CEdit m_editInput;
	CListBox m_listWords;
	afx_msg void OnEnChangeEditInput();

private:
	std::vector<CString> bip39Words;
	void UpdateWordList(const CString& filter);
public:
	CStatic m_NoWordsFound;
};
