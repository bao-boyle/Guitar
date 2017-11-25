#ifndef FILEVIEWWIDGET_H
#define FILEVIEWWIDGET_H

#include <QWidget>

#include "TextEditorWidget.h"

class QScrollBar;
struct PreEditText;
class MainWindow;

namespace Ui {
class FileViewWidget;
}

enum class FileViewType {
	None,
	Text,
	Image,
};

class FileViewWidget : public QWidget
{
	Q_OBJECT

public:
	explicit FileViewWidget(QWidget *parent = 0);
	~FileViewWidget();

	void setViewType(FileViewType type);

	void setImage(QString mimetype, const QByteArray &ba);

	void setDiffMode(TextEditorEnginePtr editor_engine, QScrollBar *vsb, QScrollBar *hsb);

	int latin1Width() const;
	int lineHeight() const;

	TextEditorTheme const *theme() const;
	void setDocument(const QList<Document::Line> *source);
	void scrollToTop();
//	void write(int c);
//	void write(const char *ptr, int len = -1);
//	void write(QString text);
	void write(QKeyEvent *e);
	void refrectScrollBar();
	void move(int cur_row, int cur_col, int scr_row, int scr_col, bool auto_scroll);

	TextEditorWidget *texteditor();
	void bind(MainWindow *mw);
private:
	Ui::FileViewWidget *ui;
};

#endif // FILEVIEWWIDGET_H
