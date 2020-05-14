#include "c.h"

void c::saveUsersStatus()
{
	QSettings app("notepad", "selectStatus");
	//保存用户的选择以及窗口的位置和大小.
	app.setValue("lineWrap", m_lineWrapAction->isChecked());
	app.setValue("statusBar", m_statusBarAction->isChecked());
	app.setValue("pos", this->pos());
	app.setValue("size", this->size());
	//对于字体,颜色就不进行保存了...
}
void c::initUsersStatus()
{
	QSettings app("notepad", "selectStatus");
	//保存用户的选择以及窗口的位置和大小.
	bool lineWrapSign = app.value("lineWrap").toBool();
	bool statusBarSign = app.value("statusBar").toBool();
	QPoint pos = app.value("pos").toPoint();
	QSize size = app.value("size").toSize();

	this->move(pos);
	this->resize(size);
	m_lineWrapAction->setChecked(lineWrapSign);
	m_statusBarAction->setChecked(statusBarSign);

	if (lineWrapSign)
		lineWrapSlot(true);
	if (statusBarSign)
		showStatusBarSlot(true);
}

c::c(QWidget *parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);

	m_isChanged = false;
	m_isSaved = false;
	m_isFinded = false;
	m_isChecked = false;
    m_filePath = ("新建文本文档.txt");
	
	m_findDialog = new FindDialog(this);
	m_replaceDialog = new ReplaceDialog(this);

	initTextEdit();
	initMenuBar();
	initToolBar();
	initGotoDialog();
	initStatusBar();
	initContextMenu();
	initConnect();

	//如果是第一次登陆的话,那么注册表中的这项基本都是0.如果不是第一次登陆的话,会自动根据上一次的登陆情况进行信息配置.
	QSettings app("notepad", "selectStatus");
	QPoint pos = app.value("pos").toPoint();

	if (!pos.isNull())
	{
		//初始化用户上一次登录的选择.
		initUsersStatus();
	}
}

c::~c()
{
	delete m_textEdit;
}
void c::initTextEdit()
{
	//创建一个widget.
	QWidget *widget = new QWidget();

	//设置widget的布局.
	QHBoxLayout *layout = new QHBoxLayout();
	m_textEdit = new QTextEdit();
	layout->addWidget(m_textEdit);
	
	//设置它的布局.主窗口自定义布局就要按照这样的方式.
	widget->setLayout(layout);
	this->setCentralWidget(widget);

	//设置文本编辑框的滚动条策略.默认是Qt::ScrollBarAsNeeded.初始化时设置为开启.
	m_textEdit->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOn);
	m_textEdit->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOn);

	//刚开始文本编辑框的换行模式是不换行的.
	m_textEdit->setLineWrapMode(QTextEdit::NoWrap);

	//设置文本编辑框的右键菜单策略.
	m_textEdit->setContextMenuPolicy(Qt::CustomContextMenu);
	
	//禁用文本编辑框的接受拖拽.因为QTextEdit默认实现了有关拖拽的虚函数.会吞噬掉拖拽进来的信号,所以要关闭,不懂也没事,关闭就行.
	m_textEdit->setAcceptDrops(false);
	//打开主窗口接受拖放的功能.
	this->setAcceptDrops(true);

	//设置主窗口的标题.
    this->setWindowTitle(m_filePath + (" - 记事本"));
	//设置主窗口左上角的图标.
    this->setWindowIcon(QIcon(":/Resources/Icons/document.png"));
	//设置主窗口的初始大小.1000.800
	this->resize(600,400);

	//设置被选中的颜色.
	m_textEdit->setStyleSheet("selection-background-color: rgb(85, 85, 255);");
}
void c::initGotoDialog()
{
	m_gotoDialog = new QInputDialog;
    m_gotoDialog->setWindowTitle(("转到指定行"));
    m_gotoDialog->setOkButtonText(("转到"));
    m_gotoDialog->setCancelButtonText(("取消"));
	m_gotoDialog->setTextEchoMode(QLineEdit::Normal);
    m_gotoDialog->setLabelText(("行号(&L)"));
	m_gotoDialog->setInputMode(QInputDialog::IntInput);

	m_gotoDialog->setIntMinimum(1);
	m_gotoDialog->setIntMaximum(10000000000000);
}
void c::initMenuBar()
{
	//创建菜单和按钮.
    m_fileMenu = new QMenu(("文件(&F)"));
    m_editMenu = new QMenu(("编辑(&E)"));
    m_formatMenu = new QMenu(("格式(&O)"));
    m_lookMenu = new QMenu(("查看(&V)"));
    m_helptMenu = new QMenu(("帮助(&H)"));
    m_newAction = new QAction(("新建(&N)"), this); m_newAction->setShortcut(tr("Ctrl+N")); m_newAction->setIcon(QIcon(":/Resources/Icons/new.png"));
    m_openAction = new QAction(("打开(&O)..."), this); m_openAction->setShortcut(tr("Ctrl+O")); m_openAction->setIcon(QIcon(":/Resources/Icons/open.png"));
    m_saveAction = new QAction(("保存(&S)"), this); m_saveAction->setShortcut(tr("Ctrl+S")); m_saveAction->setIcon(QIcon(":/Resources/Icons/save.png"));
    m_saveAsAction = new QAction(("另存为(&A)..."), this); m_saveAsAction->setIcon(QIcon(":/Resources/Icons/saveAs.png"));
    m_pageSetAction = new QAction(("页面设置(&U)..."), this);
    m_printAction = new QAction(("打印(&P)..."), this); m_printAction->setShortcut(tr("Ctrl+P")); m_printAction->setIcon(QIcon(":/Resources/Icons/print.png"));
    m_exitAction = new QAction(("退出(&X)"), this); m_exitAction->setIcon(QIcon(":/Resources/Icons/exit.png"));
    m_undoAction = new QAction(("撤销(&U)"), this); m_undoAction->setShortcut(tr("Ctrl+Z")); m_undoAction->setIcon(QIcon(":/Resources/Icons/undo.png"));
    m_cutAction = new QAction(("剪切(&T)"), this); m_cutAction->setShortcut(tr("Ctrl+X")); m_cutAction->setIcon(QIcon(":/Resources/Icons/cut.png"));
    m_copyAction = new QAction(("复制(&C)"), this); m_copyAction->setShortcut(tr("Ctrl+C")); m_copyAction->setIcon(QIcon(":/Resources/Icons/copy.png"));
    m_pasteAction = new QAction(("粘贴(&P)"), this); m_pasteAction->setShortcut(tr("Ctrl+V")); m_pasteAction->setIcon(QIcon(":/Resources/Icons/paste.png"));
    m_delAction = new QAction(("删除(&L)"), this); m_delAction->setShortcut(tr("Del")); m_delAction->setIcon(QIcon(":/Resources/Icons/del.png"));
    m_findAction = new QAction(("查找(&F)..."), this); m_findAction->setShortcut(tr("Ctrl+F"));
    m_findAnotherAction = new QAction(("查找下一个(&N)"), this); m_findAnotherAction->setShortcut(tr("F3"));
    m_replaceAction = new QAction(("替换(&R)..."), this); m_replaceAction->setShortcut(tr("Ctrl+H"));
    m_gotoAction = new QAction(("转到(&G)..."), this); m_gotoAction->setShortcut(tr("Ctrl+G")); m_gotoAction->setIcon(QIcon(":/Resources/Icons/goto.png"));
    m_selectAllAction = new QAction(("全选(&A)"), this); m_selectAllAction->setShortcut(tr("Ctrl+A"));
    m_dateAction = new QAction(("时间/日期(&D)"), this); m_dateAction->setShortcut(tr("F5")); m_dateAction->setIcon(QIcon(":/Resources/Icons/date.png"));
    m_lineWrapAction = new QAction(("自动换行(&W)"), this);
    m_fontAction = new QAction(("字体(&F)..."), this); m_fontAction->setIcon(QIcon(":/Resources/Icons/font.png"));
    m_colorAction = new QAction(("颜色(&C)"), this); m_colorAction->setIcon(QIcon(":/Resources/Icons/color.png"));
    m_statusBarAction = new QAction(("状态栏(&S)"), this);
    m_aboutAction = new QAction(("关于作者(&A)"), this);
	
	//分别把按钮项加入到菜单中.
	m_fileMenu->addAction(m_newAction);
	m_fileMenu->addAction(m_openAction);
	m_fileMenu->addAction(m_saveAction);
	m_fileMenu->addAction(m_saveAsAction);
	m_fileMenu->addSeparator();
	m_fileMenu->addAction(m_pageSetAction);
	m_fileMenu->addAction(m_printAction);
	m_fileMenu->addSeparator();
	m_fileMenu->addAction(m_exitAction);
	//
	m_editMenu->addAction(m_undoAction);
	m_editMenu->addSeparator();
	m_editMenu->addAction(m_cutAction);
	m_editMenu->addAction(m_copyAction);
	m_editMenu->addAction(m_pasteAction);
	m_editMenu->addAction(m_delAction);
	m_editMenu->addSeparator();
	m_editMenu->addAction(m_findAction);
	m_editMenu->addAction(m_findAnotherAction);
	m_editMenu->addAction(m_replaceAction);
	m_editMenu->addAction(m_gotoAction);
	m_editMenu->addSeparator();
	m_editMenu->addAction(m_selectAllAction);
	m_editMenu->addAction(m_dateAction);
	//
	m_formatMenu->addAction(m_lineWrapAction);
	m_formatMenu->addAction(m_fontAction);
	m_formatMenu->addAction(m_colorAction);
	//
	m_lookMenu->addAction(m_statusBarAction);
	//
	m_helptMenu->addAction(m_aboutAction);
	//把菜单项加入到主菜单中.
	ui.menuBar->addMenu(m_fileMenu);
	ui.menuBar->addMenu(m_editMenu);
	ui.menuBar->addMenu(m_formatMenu);
	ui.menuBar->addMenu(m_lookMenu);
	ui.menuBar->addMenu(m_helptMenu);

	//初始设置以下按钮不能被点击.
	m_undoAction->setEnabled(false);
	m_cutAction->setEnabled(false);
	m_copyAction->setEnabled(false);
	m_delAction->setEnabled(false);
	m_findAction->setEnabled(false);
	m_findAnotherAction->setEnabled(false);
	
	//设置以下按钮可以被按下.
	m_lineWrapAction->setCheckable(true);
	m_statusBarAction->setCheckable(true);

	
}
void c::initStatusBar()
{
	m_firstStatusLabel = new QLabel();
	m_secondStatusLabel = new QLabel();

	//把label加入到状态栏中,并且设置拉伸比例.
	ui.statusBar->addWidget(m_firstStatusLabel,3);
	ui.statusBar->addWidget(m_secondStatusLabel,1);
	//修改对齐格式.
	m_secondStatusLabel->setAlignment(Qt::AlignCenter);

	//隐藏.
    //ui.statusBar->hide();
}
void c::initConnect()
{
	connect(m_textEdit, SIGNAL(customContextMenuRequested(const QPoint&)), this, SLOT(showContextMenuSlot(const QPoint&)));
	connect(m_textEdit, SIGNAL(undoAvailable(bool)),this, SLOT(undoSlot(bool)));
	connect(m_textEdit, SIGNAL(copyAvailable(bool)), this, SLOT(copySlot(bool)));
	connect(m_textEdit, SIGNAL(textChanged()), this, SLOT(enableButtonSlot()));
	connect(m_textEdit, SIGNAL(cursorPositionChanged()), this, SLOT(showStatusBarTextSlot()));	

	connect(m_findDialog, SIGNAL(findText(QString, bool, int)), this, SLOT(findTextSlot(QString, bool, int)));
	connect(m_replaceDialog, SIGNAL(findText(QString,bool)), this, SLOT(findSlot(QString,bool)));
	connect(m_replaceDialog, SIGNAL(replaceText(QString, QString, bool)), this, SLOT(replaceTextSlot(QString, QString, bool)));
	connect(m_replaceDialog, SIGNAL(replaceAllText(QString,QString,bool)), this, SLOT(replaceAllSlot(QString,QString,bool)));

	//连接按钮的信号与槽.
	//文件菜单.
	connect(m_newAction, SIGNAL(triggered()),this, SLOT(createNewFileSlot()));
	connect(m_openAction, SIGNAL(triggered()), this, SLOT(openFileSlot()));
	connect(m_saveAction, SIGNAL(triggered()), this, SLOT(saveFileSlot()));
	connect(m_saveAsAction, SIGNAL(triggered()), this, SLOT(saveAsFileSlot()));
	connect(m_pageSetAction, SIGNAL(triggered()),this, SLOT(setPageSlot()));
	connect(m_printAction, SIGNAL(triggered()),this, SLOT(showPrintDialogSlot()));
	connect(m_exitAction, SIGNAL(triggered()),this, SLOT(exitAppSlot()));

	//编辑菜单.
	connect(m_undoAction, SIGNAL(triggered()), m_textEdit, SLOT(undo()));
	connect(m_contextMenuUndoAction, SIGNAL(triggered()), m_textEdit, SLOT(undo()));
	connect(m_cutAction, SIGNAL(triggered()), m_textEdit, SLOT(cut()));	
	connect(m_contextMenuCutAction, SIGNAL(triggered()), m_textEdit, SLOT(cut()));
	connect(m_copyAction, SIGNAL(triggered()), m_textEdit, SLOT(copy()));
	connect(m_contextMenuCopyAction, SIGNAL(triggered()), m_textEdit, SLOT(copy()));
	connect(m_pasteAction, SIGNAL(triggered()), m_textEdit, SLOT(paste()));
	connect(m_contextMenuPasteAction, SIGNAL(triggered()), m_textEdit, SLOT(paste()));
	connect(m_delAction, SIGNAL(triggered()), this, SLOT(delSelectedTextSlot()));
	connect(m_contextMenuDelAction, SIGNAL(triggered()), this, SLOT(delSelectedTextSlot()));
	connect(m_findAction, SIGNAL(triggered()), this, SLOT(showFindDialogSlot()));
	connect(m_findAnotherAction, SIGNAL(triggered()), this, SLOT(findAnotherSlot()));
	connect(m_replaceAction, SIGNAL(triggered()), this, SLOT(showReplaceDialogSlot()));
	connect(m_gotoAction, SIGNAL(triggered()), this, SLOT(gotoLineSlot()));
	connect(m_selectAllAction, SIGNAL(triggered()), m_textEdit, SLOT(selectAll()));
	connect(m_contextMenuSelectAllAction, SIGNAL(triggered()), m_textEdit, SLOT(selectAll()));
	connect(m_dateAction, SIGNAL(triggered()), this, SLOT(appendDateSlot()));
	connect(m_lineWrapAction, SIGNAL(toggled(bool)), this, SLOT(lineWrapSlot(bool)));
	connect(m_fontAction, SIGNAL(triggered()), this, SLOT(setFontSlot()));
	connect(m_colorAction, SIGNAL(triggered()), this, SLOT(setColorSlot()));
	connect(m_contextMenuReSelectAction, SIGNAL(triggered()), this, SLOT(cancelTextSelectedSlot()));

	connect(m_statusBarAction, SIGNAL(toggled(bool)), this, SLOT(showStatusBarSlot(bool)));

	connect(m_aboutAction, SIGNAL(triggered()), this, SLOT(showWriterSlot()));
	
}
void c::createNewFileSlot()
{
	int status = 0;
	//判断文本的内容是否被修改过.
	if (m_isChanged)
	{
		status = showSavedDialog();
	}
	if (status == tag_cancel)
		return;

	//以下为必要动作,无论用户如何选择.
	//修改标识符.清空编辑框.
	m_isSaved = false;
	m_isChanged = false;
	m_textEdit->clear();
    m_filePath = ("无标题.txt");
    this->setWindowTitle(m_filePath + ("-记事本"));
}
int c::showSavedDialog()
{
	QMessageBox mes(this);
	//修改标题和文本.
    mes.setText(("是否将更改保存到:") + m_filePath);
    mes.setWindowTitle(("记事本"));
	//设置默认按钮.
	mes.setStandardButtons(QMessageBox::Save | QMessageBox::No | QMessageBox::Cancel);
	mes.setDefaultButton(QMessageBox::Save);
	//修改按钮显示的文本.
    mes.setButtonText(QMessageBox::Save, ("保存(&S)"));
    mes.setButtonText(QMessageBox::No, ("不保存(&N)"));
    mes.setButtonText(QMessageBox::Cancel, ("取消"));

	//用户的选择.
	int status = mes.exec();
	if (status == QMessageBox::Save)
	{
		//如果文件存在.
		if (m_isSaved)
		{
			saveFile(m_filePath);
			m_isSaved = true;
			m_isChanged = false;
		}
		else
			saveAsFileSlot();
		return tag_save;
	}
	else if (status == QMessageBox::No)
	{
		return tag_notSave;
	}
	else
	{
		return tag_cancel;
	}
	//其他两个选项,选择了会自动关闭对话框.
}

void c::saveFile(QString filePath)
{
	//只写的方式打开文件.
	QFile *file = new QFile(filePath);
	bool ok = file->open(QIODevice::WriteOnly);
	if (ok)
	{
		//连接到文本流中.
		QTextStream stream(file);
		stream << m_textEdit->toPlainText();
	}
	//关闭文件.
	file->close();
}
void c::readFile(QString filePath)
{
	//记录新打开文件的路径.
	m_filePath = filePath;

	QFile *file = new QFile(filePath);
	bool ok = file->open(QIODevice::ReadOnly);
	if (ok)
	{
		QTextStream stream(file);
        this->setWindowTitle(getFileName() + (" - 记事本"));
		m_textEdit->setPlainText(stream.readAll());
		file->close();
	}
}
QString c::getFileName()
{
	QFileInfo info(m_filePath);
	return info.fileName();
}

//
void c::openFileSlot()
{
	if (m_isChanged)
	{
		int status = showSavedDialog();
		//如果是取消,则不会打开文件.
		if (status == tag_cancel)
			return;
	}

    QString filePath = QFileDialog::getOpenFileName(this, QString("打开"), QDir::currentPath(), ("文本文档(*.txt);;所有文件(*.*)"));
	//检查是否为空.如果为空,说明用户没有选择文件,直接关闭了对话框.
	if (filePath.isEmpty())
		return;
	readFile(filePath);
	//修改标识符.
	m_isSaved = true;
	m_isChanged = false;
}
void c::saveFileSlot()
{
	int status = 0;
	//如果文件存在.
	if (m_isSaved)
	{
		saveFile(m_filePath);
		m_isSaved = true;
		m_isChanged = false;
	}
	else
	{
		status = saveAsFileSlot();
		if (status == tag_save)
		{
			m_isSaved = true;
			m_isChanged = false;
			m_filePath = m_tempPath;
			//修改标题.
            this->setWindowTitle(getFileName() + (" - 记事本"));
		}
		else
		{
			m_isSaved = false;
		}
	}
}
int c::saveAsFileSlot()
{
	//跳出保存对话框并且保存文件.
    QString filePath = QFileDialog::getSaveFileName(this, QString("另存为"), QDir::currentPath(), ("文本文档(*.txt);;所有文件(*.*)"));
	if (!filePath.isEmpty())
	{
		m_tempPath = filePath;
		saveFile(filePath);
		return tag_save;
	}
	return tag_cancel;
}
void c::setPageSlot()
{
	QPrinter printer;
	//设置页面对话框.
	QPageSetupDialog pageSetUpdlg(&printer, this);
	if (pageSetUpdlg.exec() == QDialog::Accepted)
	{
		printer.setOrientation(QPrinter::Landscape);
	}
	else
	{
		printer.setOrientation(QPrinter::Portrait);
	}
}
void c::showPrintDialogSlot()
{
	QPrinter q;
	//打印对话框.
	QPrintDialog s(&q, this);
	if (s.exec() == QDialog::Accepted)
		m_textEdit->print(&q);
}
void c::exitAppSlot()
{
	int status = 0;

	//如果被修改过.
	if (m_isChanged)
	{
		status = showSavedDialog();
		if (status == tag_cancel)
			return;
	}
	
	//关闭app.
	saveUsersStatus();
	QApplication::exit();
}

void c::enableButtonSlot()
{
	if (m_textEdit->document()->isEmpty())
	{
		m_contextMenuSelectAllAction->setEnabled(false);
		m_contextMenuReSelectAction->setEnabled(false);
		m_findAction->setEnabled(false);
		m_findAnotherAction->setEnabled(false);
	}
	else
	{
		m_contextMenuSelectAllAction->setEnabled(true);
		m_contextMenuReSelectAction->setEnabled(true);
		m_findAction->setEnabled(true);
		m_findAnotherAction->setEnabled(true);
	}
	m_isChanged = true;
}
void c::undoSlot(bool canUndo)
{
	if (canUndo)
	{
		m_undoAction->setEnabled(true);
		m_contextMenuUndoAction->setEnabled(true);
	}
	else
	{
		m_undoAction->setEnabled(false);
		m_contextMenuUndoAction->setEnabled(false);
	}
}
void c::copySlot(bool canCopy)
{
	if (canCopy)
	{
		m_cutAction->setEnabled(true);
		m_copyAction->setEnabled(true);
		m_delAction->setEnabled(true);
		m_contextMenuCutAction->setEnabled(true);
		m_contextMenuCopyAction->setEnabled(true);
		m_contextMenuDelAction->setEnabled(true);
	}
	else
	{
		m_cutAction->setEnabled(false);
		m_copyAction->setEnabled(false);
		m_delAction->setEnabled(false);
		m_contextMenuCutAction->setEnabled(false);
		m_contextMenuCopyAction->setEnabled(false);
		m_contextMenuDelAction->setEnabled(false);
	}
}
//重写的虚函数.
void c::closeEvent(QCloseEvent *event)
{
	exitAppSlot();
	//如果用户点击取消,则不关闭程序.
	event->ignore();
}
void c::dragEnterEvent(QDragEnterEvent *event)
{
	if (event->mimeData()->hasUrls())
	{
		event->setDropAction(Qt::CopyAction);
		event->accept();
	}
}
void c::dropEvent(QDropEvent *event)
{
	int status = 0;

	//如果被修改过.
	if (m_isChanged)
	{
		status = showSavedDialog();
	}

	//获取拖入的文件的路径.
	QList<QUrl> s = event->mimeData()->urls();
	QString path = s[0].toLocalFile();
	//读取文件内容.
	readFile(path);
	m_isChanged = false;
	m_isSaved = true;
}
void c::enterEvent(QEvent *event)
{
	QString contents = QApplication::clipboard()->text();
	if (contents.isEmpty())
	{
		m_pasteAction->setEnabled(false);
		m_contextMenuPasteAction->setEnabled(false);
	}
	else
	{
		m_pasteAction->setEnabled(true);
		m_contextMenuPasteAction->setEnabled(true);
	}
}
void c::initContextMenu()
{
	m_contextMenu = new QMenu;
    m_contextMenuUndoAction = new QAction(("撤销(U)"), this);
    m_contextMenuCutAction = new QAction(("剪切(T)"), this);
    m_contextMenuCopyAction = new QAction(("复制(C)"), this);
    m_contextMenuPasteAction = new QAction(("粘贴(P)"), this);
    m_contextMenuDelAction = new QAction(("删除(D)"), this);
    m_contextMenuSelectAllAction = new QAction(("全选(A)"), this);
    m_contextMenuReSelectAction = new QAction(("汉字重选(R)"), this);

	m_contextMenu->addAction(m_contextMenuUndoAction);
	m_contextMenu->addSeparator();
	m_contextMenu->addAction(m_contextMenuCutAction);
	m_contextMenu->addAction(m_contextMenuCopyAction);
	m_contextMenu->addAction(m_contextMenuPasteAction);
	m_contextMenu->addAction(m_contextMenuDelAction);
	m_contextMenu->addSeparator();
	m_contextMenu->addAction(m_contextMenuSelectAllAction);
	m_contextMenu->addSeparator();
	m_contextMenu->addAction(m_contextMenuReSelectAction);

	m_contextMenuUndoAction->setEnabled(false);
	m_contextMenuCopyAction->setEnabled(false);
	m_contextMenuCopyAction->setEnabled(false);
	m_contextMenuDelAction->setEnabled(false);
	m_contextMenuCutAction->setEnabled(false);
}
void c::showContextMenuSlot(const QPoint& pos)
{
	m_contextMenu->exec(QCursor::pos());
}
void c::delSelectedTextSlot()
{
	//取得文本编辑框中的光标.
	QTextCursor *textCursor = new QTextCursor(m_textEdit->textCursor());
	//调用成员方法删除被选中文本.
	textCursor->removeSelectedText();
}
void c::showFindDialogSlot()
{
	m_findDialog->clear();
	m_findDialog->setFindText(m_findText);
	//如果被隐藏了.则显示.
	if (m_findDialog->isHidden())
		m_findDialog->show();
	//反之,让它上升到顶层且属于激活状态.
	else
	{
		m_findDialog->raise();
		m_findDialog->activateWindow();
	}	
}
void c::findTextSlot(QString findText, bool checkSign, int dirSign)
{
	m_findText = findText;
	m_sSign = checkSign;
	m_dir = dirSign;

	//获取当前的光标位置.查找时作为当前光标的参数.
	QTextCursor *textCursor = new QTextCursor(m_textEdit->textCursor());
	//获取文本编辑看的文档格式.因为QTextDocument下有可以直接使用的查找方法.
	QTextDocument *document = m_textEdit->document();

	QTextDocument::FindFlag s; 
	QTextDocument::FindFlag dir;

	if (checkSign)		//如果区分大小写.
		s = QTextDocument::FindCaseSensitively;
	if (dirSign == 1)		//如果向上被选中.
		dir = QTextDocument::FindBackward;

	//找到匹配的位置.
	QTextCursor matchPos = document->find(findText, *textCursor, s | dir);
	if (!matchPos.isNull())		//如果不为空.
	{
		m_textEdit->setTextCursor(matchPos);
	}
	else
	{
        QMessageBox::information(this, QString("记事本"), QString("找不到") + "\"" + findText + "\"");
	}
	//修改标识符,已经查找过,所以在点击查找下一个就不会跳出对话框了.
	m_isFinded = true;
}
void c::findAnotherSlot()
{
	//如果没有查找过.则先显示查找对话框.
	if (!m_isFinded)
		showFindDialogSlot();
	//这里应该有其他的办法吧,没去细想.
	else
		findTextSlot(m_findText, m_sSign, m_dir);

}
void c::gotoLineSlot()
{
	QTextCursor *textCursor = new QTextCursor(m_textEdit->textCursor());
	//设置当前行数.
	m_gotoDialog->setIntValue(textCursor->blockNumber() + 1);

	QTextDocument *document = m_textEdit->document();
	int totalLineCount = document->blockCount();

	Goto_action:int status = m_gotoDialog->exec();
	if (status == QDialog::Accepted)
	{
		int n = m_gotoDialog->intValue();	//要求转到的行数.
		int m = textCursor->blockNumber() + 1;	//当前光标所在的行数.

		if (n <= totalLineCount)
		{
			if (n < m)		//如果要求转到的行在当前行的前面，就是让光标往前移.
			{
				textCursor->movePosition(QTextCursor::PreviousBlock, QTextCursor::MoveAnchor, m - n);
			}
			else if (n > m)
			{
				textCursor->movePosition(QTextCursor::NextBlock, QTextCursor::MoveAnchor, n - m);
			}
			m_textEdit->setTextCursor(*textCursor);
		}
		else
		{
            QMessageBox::information(NULL, QString("记事本-跳行"), QString("行数超过了总行数"), QMessageBox::Ok);
			m_gotoDialog->setIntValue(totalLineCount);
			gotoLineSlot();
		}
	}
}
void c::appendDateSlot()
{
	//获取当前的时间日期,转化为指定格式.插入到文本的最后面,且不换行.
	QString str = QDateTime::currentDateTime().toString("hh:mm yyyy/M/d");
	m_textEdit->insertPlainText(str);
	//下面这种方法会自动换行.
	//m_textEdit->append(str);
}
void c::setFontSlot()
{
	bool ok;
	QFont currentFont = QFontDialog::getFont(&ok);
	if (ok)
	{
		m_textEdit->setFont(currentFont);
	}
}
void c::setColorSlot()
{
	QColor color = QColorDialog::getColor(Qt::black, this);
	if (color.isValid())
	{
		m_textEdit->setTextColor(color);
	}
}
void c::lineWrapSlot(bool sign)
{
	if (sign)
	{
		m_gotoAction->setEnabled(false);
		m_statusBarAction->setEnabled(false);
		//如果显示状态栏被按下了.
		if (m_statusBarAction->isChecked())
		{
			m_statusBarAction->setChecked(false);
			ui.statusBar->hide();
			m_isChecked = true;
		}
		
		//设置水平滚动策略总是关闭的,因为自动换行了嘛.
		m_textEdit->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
		//同时也需要修改换行模式为根据当前窗口的大小进行换行,这里只是单纯的换行,不管被分割的单词.
		m_textEdit->setLineWrapMode(QTextEdit::WidgetWidth);
	}
	else
	{
		m_gotoAction->setEnabled(true);
		m_statusBarAction->setEnabled(true);

		m_textEdit->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOn);
		m_textEdit->setLineWrapMode(QTextEdit::NoWrap);

		if (m_isChecked)
		{
			m_statusBarAction->setChecked(true);
			ui.statusBar->show();
		}
	}
}
void c::showStatusBarSlot(bool sign)
{
	if (sign)
	{
		ui.statusBar->show();
		showStatusBarTextSlot();
		m_isChecked = true;
	}
	else
	{
		ui.statusBar->hide();
		m_isChecked = false;
	}

}
void c::showStatusBarTextSlot()
{
	QTextCursor *textCursor = new QTextCursor(m_textEdit->textCursor());
	//获取行数.
	QString lineCount = QString::number(textCursor->blockNumber() + 1);
	//获取列数.
	QString columnCount = QString::number(textCursor->columnNumber() + 1);

    m_secondStatusLabel->setText(QString("第%1行,第%2列").arg(lineCount).arg(columnCount));
}
void c::showWriterSlot()
{
    QMessageBox::information(this, QString("关于作者"), QString("<a href='https://www.shiguangkey.com' > 通往潭州课堂 </a>"));
}
void c::cancelTextSelectedSlot()
{
	QTextCursor cursor = m_textEdit->textCursor();
	//清空被选中的文本.
	cursor.clearSelection();
	//设置为文本编辑框的光标选择.
	m_textEdit->setTextCursor(cursor);
}
void c::showReplaceDialogSlot()
{
	m_replaceDialog->clear();
	m_replaceDialog->setFindText(m_findText);
	m_replaceDialog->setReplaceText(m_replaceText);
	//如果被隐藏了.则显示.
	if (m_replaceDialog->isHidden())
		m_replaceDialog->show();
	//反之,让它上升到顶层且属于激活状态.
	else
	{
		m_replaceDialog->raise();
		m_replaceDialog->activateWindow();
	}
}
void c::findSlot(QString text, bool sign)
{
	m_findText = text;
	m_sSign = sign;

	//获取当前的光标位置.查找时作为当前光标的参数.
	QTextCursor *textCursor = new QTextCursor(m_textEdit->textCursor());
	//获取文本编辑看的文档格式.因为QTextDocument下有可以直接使用的查找方法.
	QTextDocument *document = m_textEdit->document();

	QTextDocument::FindFlag s;

	if (sign)		//如果区分大小写.
		s = QTextDocument::FindCaseSensitively;

	//找到匹配的位置.
	QTextCursor matchPos = document->find(text, *textCursor, s);
	if (!matchPos.isNull())		//如果不为空.
	{
		m_textEdit->setTextCursor(matchPos);
	}
	else
	{
        QMessageBox::information(this, QString("记事本"), QString("找不到") + "\"" + text + "\"");
	}
	//修改标识符,已经查找过,所以在点击查找下一个就不会跳出对话框了.
	m_isFinded = true;
}
void c::replaceTextSlot(QString text, QString replaceText, bool sign)
{
	QTextCursor *textCursor = new QTextCursor(m_textEdit->textCursor());
	textCursor->movePosition(QTextCursor::Start, QTextCursor::MoveAnchor);
	m_replaceText = replaceText;

	QTextDocument *document = m_textEdit->document();

	QTextDocument::FindFlag s;
	if (sign)		//如果选择了	区分大小写.
		s = QTextDocument::FindCaseSensitively;

	auto temp = document->find(text, *textCursor, s);
	if (!temp.isNull())
	{
		temp.insertText(replaceText);
		temp.movePosition(QTextCursor::PreviousCharacter, QTextCursor::KeepAnchor, replaceText.size());
		m_textEdit->setTextCursor(temp);
	}
	else
	{
        QMessageBox::information(this, QString("记事本"), QString("找不到") + "\"" + text + "\"");
	}
	//修改标识符,已经查找过,所以在点击查找下一个就不会跳出对话框了.
	m_isFinded = true;
}
void c::replaceAllSlot(QString text, QString replaceText, bool sign)
{
	QTextCursor *textCursor = new QTextCursor(m_textEdit->textCursor());
	textCursor->movePosition(QTextCursor::Start, QTextCursor::MoveAnchor);	//设置鼠标从文档的开头开始.
	
	QTextDocument *document = m_textEdit->document();

	m_findText = text;
	m_replaceText = replaceText;

	QTextDocument::FindFlags s;
	if (sign)
		s = QTextDocument::FindCaseSensitively;
	while (1)
	{
		QTextCursor temp = document->find(text, *textCursor, s);

		if (!temp.isNull())
		{
			temp.insertText(replaceText);
			m_textEdit->setTextCursor(temp);
		}
		else
		{
			return;
		}
	}
	//修改标识符,已经查找过,所以在点击查找下一个就不会跳出对话框了.
	m_isFinded = true;
}

void c::initToolBar()
{
	ui.mainToolBar->addAction(m_newAction);
	ui.mainToolBar->addAction(m_openAction);
	ui.mainToolBar->addAction(m_saveAction);
	ui.mainToolBar->addAction(m_saveAsAction);
	ui.mainToolBar->addAction(m_undoAction);
	ui.mainToolBar->addAction(m_cutAction);
	ui.mainToolBar->addAction(m_copyAction);
	ui.mainToolBar->addAction(m_pasteAction);
	ui.mainToolBar->addAction(m_delAction);
	ui.mainToolBar->addAction(m_gotoAction);
	ui.mainToolBar->addAction(m_dateAction);
	ui.mainToolBar->addAction(m_fontAction);
	ui.mainToolBar->addAction(m_colorAction);
	ui.mainToolBar->addAction(m_exitAction);
}
