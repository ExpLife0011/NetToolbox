#ifndef UITreeView_h__
#define UITreeView_h__

#pragma once

#include <vector>

namespace DuiLib {
	class CTreeViewUI;
	class CCheckBoxUI;
	class CLabelUI;
	class COptionUI;

	class UILIB_API CTreeNodeUI: public CListContainerElementUI {
		DECLARE_DUICONTROL (CTreeNodeUI)
	public:
		CTreeNodeUI (CTreeNodeUI* _ParentNode = nullptr);
		virtual ~CTreeNodeUI (void);

	public:
		string_view_t GetClass () const;
		LPVOID GetInterface (string_view_t pstrName);
		void DoEvent (TEventUI& event);
		void Invalidate ();
		bool Select (bool bSelect = true);
		bool SelectMulti (bool bSelect = true);

		bool Add (CControlUI* _pTreeNodeUI);
		bool AddAt (CControlUI* pControl, int iIndex);
		bool Remove (CControlUI* pControl);

		void SetVisibleTag (bool _IsVisible);
		bool GetVisibleTag ();
		void SetItemText (string_view_t pstrValue);
		CDuiString GetItemText ();
		void CheckBoxSelected (bool _Selected);
		bool IsCheckBoxSelected () const;
		bool IsHasChild () const;
		long GetTreeLevel () const;
		bool AddChildNode (CTreeNodeUI* _pTreeNodeUI);
		bool RemoveAt (CTreeNodeUI* _pTreeNodeUI);
		void SetParentNode (CTreeNodeUI* _pParentTreeNode);
		CTreeNodeUI* GetParentNode ();
		long GetCountChild ();
		void SetTreeView (CTreeViewUI* _CTreeViewUI);
		CTreeViewUI* GetTreeView ();
		CTreeNodeUI* GetChildNode (int _nIndex);
		void SetVisibleFolderBtn (bool _IsVisibled);
		bool GetVisibleFolderBtn ();
		void SetVisibleCheckBtn (bool _IsVisibled);
		bool GetVisibleCheckBtn ();
		void SetItemTextColor (DWORD _dwItemTextColor);
		DWORD GetItemTextColor () const;
		void SetItemHotTextColor (DWORD _dwItemHotTextColor);
		DWORD GetItemHotTextColor () const;
		void SetSelItemTextColor (DWORD _dwSelItemTextColor);
		DWORD GetSelItemTextColor () const;
		void SetSelItemHotTextColor (DWORD _dwSelHotItemTextColor);
		DWORD GetSelItemHotTextColor () const;
		void SetAttribute (string_view_t pstrName, string_view_t pstrValue);

		CStdPtrArray GetTreeNodes ();
		int			 GetTreeIndex ();
		int			 GetNodeIndex ();

	public:
		CHorizontalLayoutUI	*GetTreeNodeHoriznotal () const {
			return pHoriz;
		};
		CCheckBoxUI			*GetFolderButton () const {
			return pFolderButton;
		};
		CLabelUI				*GetDottedLine () const {
			return pDottedLine;
		};
		CCheckBoxUI			*GetCheckBox () const {
			return pCheckBox;
		};
		COptionUI				*GetItemButton () const {
			return pItemButton;
		};

	private:
		CTreeNodeUI* GetLastNode ();
		CTreeNodeUI* CalLocation (CTreeNodeUI* _pTreeNodeUI);

	private:
		long					m_iTreeLavel			= 0;
		bool					m_bIsVisable			= true;
		bool					m_bIsCheckBox			= false;
		DWORD					m_dwItemTextColor		= 0x00000000;
		DWORD					m_dwItemHotTextColor	= 0;
		DWORD					m_dwSelItemTextColor	= 0;
		DWORD					m_dwSelItemHotTextColor	= 0;

		CTreeViewUI				*pTreeView				= nullptr;
		CHorizontalLayoutUI		*pHoriz;
		CCheckBoxUI				*pFolderButton;
		CLabelUI				*pDottedLine;
		CCheckBoxUI				*pCheckBox;
		COptionUI				*pItemButton;
		CTreeNodeUI				*pParentTreeNode		= nullptr;
		CStdPtrArray			mTreeNodes;
	};

	class UILIB_API CTreeViewUI: public CListUI, public INotifyUI {
		DECLARE_DUICONTROL (CTreeViewUI)
	public:
		CTreeViewUI (void);
		virtual ~CTreeViewUI (void);

	public:
		virtual string_view_t GetClass () const;
		virtual LPVOID	GetInterface (string_view_t pstrName);

		virtual UINT GetListType ();
		virtual bool Add (CTreeNodeUI* pControl);
		virtual long AddAt (CTreeNodeUI* pControl, int iIndex);
		virtual bool AddAt (CTreeNodeUI* pControl, CTreeNodeUI* _IndexNode);
		virtual bool Remove (CTreeNodeUI* pControl);
		virtual bool RemoveAt (int iIndex);
		virtual void RemoveAll ();
		virtual bool OnCheckBoxChanged (void* param);
		virtual bool OnFolderChanged (void* param);
		virtual bool OnDBClickItem (void* param);
		virtual bool SetItemCheckBox (bool _Selected, CTreeNodeUI* _TreeNode = nullptr);
		virtual void SetItemExpand (bool _Expanded, CTreeNodeUI* _TreeNode = nullptr);
		virtual void Notify (TNotifyUI& msg);
		virtual void SetVisibleFolderBtn (bool _IsVisibled);
		virtual bool GetVisibleFolderBtn ();
		virtual void SetVisibleCheckBtn (bool _IsVisibled);
		virtual bool GetVisibleCheckBtn ();
		virtual void SetItemMinWidth (UINT _ItemMinWidth);
		virtual UINT GetItemMinWidth ();
		virtual void SetItemTextColor (DWORD _dwItemTextColor);
		virtual void SetItemHotTextColor (DWORD _dwItemHotTextColor);
		virtual void SetSelItemTextColor (DWORD _dwSelItemTextColor);
		virtual void SetSelItemHotTextColor (DWORD _dwSelHotItemTextColor);

		virtual void SetAttribute (string_view_t pstrName, string_view_t pstrValue);
	private:
		UINT m_uItemMinWidth;
		bool m_bVisibleFolderBtn;
		bool m_bVisibleCheckBtn;
	};
}


#endif // UITreeView_h__
