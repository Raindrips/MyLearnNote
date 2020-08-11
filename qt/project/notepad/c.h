#ifndef C_H
#define C_H

#include <QtWidgets/QMainWindow>
#include "ui_c.h"
#include <QTextEdit>
#include <QMenu>
#include <QAction>
#include <QHBoxLayout>
#include <QIcon>
#include <QMessageBox>
#include <QFile>
#include <QFileDialog>
#include <QTextStream>
#include <QPageSetupDialog>
#include <QPrintPreviewDialog>
#include <QPrintDialog>
#include <QPrinter>
#include <QEvent>
#include <QCloseEvent>
#include <QDropEvent>
#include <QMimeData>
#include <QClipboard>
#include <QTextCursor>
#include "FindDialog.h"
#include <QDateTime>
#include <QFontDialog>
#include <QColorDialog>
#include <QInputDialog>
#include <QSettings>
#include "ReplaceDialog.h"

class c : public QMainWindow
{
	Q_OBJECT
	typedef enum{
		tag_save = 0,
		tag_notSave = 1,
		tag_cancel = 2
	}Mes_status;
public:
	c(QWidget *parent = 0);
	~c();
protected:
	void closeEvent(QCloseEvent *event);
	void dragEnterEvent(QDragEnterEvent *event);
	void dropEvent(QDropEvent *event);
	void enterEvent(QEvent *event);
private slots:
	void createNewFileSlot();
	void openFileSlot();
	void saveFileSlot();
	int saveAsFileSlot();
	void setPageSlot();
	void exitAppSlot();
	void showPrintDialogSlot();
	void showContextMenuSlot(const QPoint&);
	void undoSlot(bool);
	void copySlot(bool);
	void delSelectedTextSlot();
	void enableButtonSlot();
	void showFindDialogSlot();
	void findTextSlot(QString, bool, int);
	void findAnotherSlot();
	void gotoLineSlot();
	void appendDateSlot();
	void setFontSlot();
	void setColorSlot();
	void lineWrapSlot(bool);
	void showStatusBarSlot(bool);
	void showStatusBarTextSlot();
	void showWriterSlot();
	void cancelTextSelectedSlot();
	void showReplaceDialogSlot();
	void findSlot(QString, bool);
	void replaceTextSlot(QString, QString, bool);
	void replaceAllSlot(QString, QString, bool);
private:
	Ui::cClass ui;
	//初始化TextEdit.
	void initTextEdit();
	void initMenuBar();
	void initConnect();
	void initContextMenu();
	void initStatusBar();
	//show是否保存的对话框.
	int showSavedDialog();
	//
	QString getFileName();
	//
	void saveFile(QString);
	//
	void readFile(QString);
	//
	void initGotoDialog();
	//
	void saveUsersStatus();
	void initUsersStatus();
	void initToolBar();

	QTextEdit *m_textEdit;
	//主菜单中的按钮.
	QMenu *m_fileMenu;
	QMenu *m_editMenu;
	QMenu *m_formatMenu;
	QMenu *m_lookMenu;
	QMenu *m_helptMenu;
	QAction *m_newAction;
	QAction *m_openAction;
	QAction *m_saveAction;
	QAction *m_saveAsAction;
	QAction *m_pageSetAction;
	QAction *m_printAction;
	QAction *m_exitAction;
	QAction *m_undoAction;
	QAction *m_cutAction;
	QAction *m_copyAction;
	QAction *m_pasteAction;
	QAction *m_delAction;
	QAction *m_findAction;
	QAction *m_findAnotherAction;
	QAction *m_replaceAction;
	QAction *m_gotoAction;
	QAction *m_selectAllAction;
	QAction *m_dateAction;
	QAction *m_lineWrapAction;
	QAction *m_fontAction;
	QAction *m_colorAction;
	QAction *m_statusBarAction;
	QAction *m_aboutAction;

	//右键菜单中的按钮.
	QMenu *m_contextMenu;
	QAction *m_contextMenuUndoAction;
	QAction *m_contextMenuCutAction;
	QAction *m_contextMenuCopyAction;
	QAction *m_contextMenuPasteAction;
	QAction *m_contextMenuDelAction;
	QAction *m_contextMenuSelectAllAction;
	QAction *m_contextMenuReSelectAction;

	//记录文件是否被保存.
	bool m_isSaved;
	bool m_isChanged;
	QString m_filePath;
	QString m_tempPath;
	bool m_isFinded;
	QString m_findText;
	QString m_replaceText;
	bool m_sSign;
	int m_dir;
	QLabel *m_firstStatusLabel;
	QLabel *m_secondStatusLabel;
	bool m_isChecked;
	QInputDialog *m_gotoDialog;
	FindDialog *m_findDialog;
	ReplaceDialog *m_replaceDialog;
	
};

#endif // C_H
