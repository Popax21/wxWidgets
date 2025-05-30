/////////////////////////////////////////////////////////////////////////////
// Name:        wx/msw/stattext.h
// Purpose:     wxStaticText class
// Author:      Julian Smart
// Created:     01/02/97
// Copyright:   (c) Julian Smart
// Licence:     wxWindows licence
/////////////////////////////////////////////////////////////////////////////

#ifndef _WX_STATTEXT_H_
#define _WX_STATTEXT_H_

class WXDLLIMPEXP_CORE wxStaticText : public wxStaticTextBase
{
public:
    wxStaticText() = default;

    wxStaticText(wxWindow *parent,
                 wxWindowID id,
                 const wxString& label,
                 const wxPoint& pos = wxDefaultPosition,
                 const wxSize& size = wxDefaultSize,
                 long style = 0,
                 const wxString& name = wxASCII_STR(wxStaticTextNameStr))
    {
        Create(parent, id, label, pos, size, style, name);
    }

    bool Create(wxWindow *parent,
                wxWindowID id,
                const wxString& label,
                const wxPoint& pos = wxDefaultPosition,
                const wxSize& size = wxDefaultSize,
                long style = 0,
                const wxString& name = wxASCII_STR(wxStaticTextNameStr));

    virtual ~wxStaticText();

    // override some methods to resize the window properly
    virtual void SetLabel(const wxString& label) override;
    virtual bool SetFont( const wxFont &font ) override;

    virtual WXDWORD MSWGetStyle(long flags, WXDWORD *exstyle = nullptr) const override;

protected:
    // implement/override some base class virtuals
#if wxUSE_MARKUP
    virtual bool DoSetLabelMarkup(const wxString& markup) override;
#endif // wxUSE_MARKUP

    virtual void DoSetSize(int x, int y, int w, int h,
                           int sizeFlags = wxSIZE_AUTO) override;
    virtual wxSize DoGetBestClientSize() const override;

    virtual bool MSWHandleMessage(WXLRESULT *result,
                                  WXUINT message,
                                  WXWPARAM wParam,
                                  WXLPARAM lParam) override;

    virtual wxString WXGetVisibleLabel() const override;
    virtual void WXSetVisibleLabel(const wxString& str) override;

#if wxUSE_MARKUP
    class wxMarkupText* m_markupText = nullptr;

    // This is only used when m_markupText is non-null.
    void WXOnPaint(wxPaintEvent& event);
#endif // wxUSE_MARKUP

    wxDECLARE_DYNAMIC_CLASS_NO_COPY(wxStaticText);
};

#endif
    // _WX_STATTEXT_H_
