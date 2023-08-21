// Bip39FinderDlg.cpp : implementation file
//

#include "pch.h"
#include "Bip39Finder.h"
#include "Bip39FinderDlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

// CBip39FinderDlg dialog
#define WM_POST_INIT (WM_USER + 1)

CBip39FinderDlg::CBip39FinderDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_BIP39FINDER_DIALOG, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CBip39FinderDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // device context for painting

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

HCURSOR CBip39FinderDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}

void CBip39FinderDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_EDIT_INPUT, m_editInput);
	DDX_Control(pDX, IDC_LIST_WORDS, m_listWords);
	DDX_Control(pDX, IDC_STATIC_WORDS_FOUND, m_NoWordsFound);
}

BEGIN_MESSAGE_MAP(CBip39FinderDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_WM_TIMER()
	ON_MESSAGE(WM_POST_INIT, &CBip39FinderDlg::OnPostInit)
	ON_EN_CHANGE(IDC_EDIT_INPUT, &CBip39FinderDlg::OnEnChangeEditInput)
END_MESSAGE_MAP()

void CBip39FinderDlg::OnTimer(UINT_PTR nIDEvent)
{
	if (nIDEvent == 1)  // Check for our timer ID
	{
		KillTimer(1);  // Stop the timer
		// Post a custom message to handle after initialization
		PostMessage(WM_POST_INIT);
	}

	CDialogEx::OnTimer(nIDEvent);
}
// CBip39FinderDlg message handlers
std::vector<CString> bip39WordsPart0 = 
{
	_T("abandon"), 	_T("ability"), 	_T("able"), 	_T("about"), 	_T("above"), 	_T("absent"), 	_T("absorb"), 	_T("abstract"), 	_T("absurd"), 	_T("abuse"), 	_T("access"), 	_T("accident"), 	_T("account"), 	_T("accuse"), 	_T("achieve"), 	_T("acid"), 	_T("acoustic"), 	_T("acquire"), 	_T("across"), 	_T("act"), 	_T("action"), 	_T("actor"), 	_T("actress"), 	_T("actual"), 	_T("adapt"), 	_T("add"), 	_T("addict"), 	_T("address"), 	_T("adjust"), 	_T("admit"), 	_T("adult"), 	_T("advance"), 	_T("advice"), 	_T("aerobic"), 	_T("affair"), 	_T("afford"), 	_T("afraid"), 	_T("again"), 	_T("age"), 	_T("agent"), 	_T("agree"), 	_T("ahead"), 	_T("aim"), 	_T("air"), 	_T("airport"), 	_T("aisle"), 	_T("alarm"), 	_T("album"), 	_T("alcohol"), 	_T("alert"), 	_T("alien"), 	_T("all"), 	_T("alley"), 	_T("allow"), 	_T("almost"), 	_T("alone"), 	_T("alpha"), 	_T("already"), 	_T("also"), 	_T("alter"), 	_T("always"), 	_T("amateur"), 	_T("amazing"), 	_T("among"), 	_T("amount"), 	_T("amused"), 	_T("analyst"), 	_T("anchor"), 	_T("ancient"), 	_T("anger"), 	_T("angle"), 	_T("angry"), 	_T("animal"), 	_T("ankle"), 	_T("announce"), 	_T("annual"), 	_T("another"), 	_T("answer"), 	_T("antenna"), 	_T("antique"), 	_T("anxiety"), 	_T("any"), 	_T("apart"), 	_T("apology"), 	_T("appear"), 	_T("apple"), 	_T("approve"), 	_T("april"), 	_T("arch"), 	_T("arctic"), 	_T("area"), 	_T("arena"), 	_T("argue"), 	_T("arm"), 	_T("armed"), 	_T("armor"), 	_T("army"), 	_T("around"), 	_T("arrange"), 	_T("arrest"),
};

std::vector<CString> bip39WordsPart1 = 
{
	_T("arrive"), 	_T("arrow"), 	_T("art"), 	_T("artefact"), 	_T("artist"), 	_T("artwork"), 	_T("ask"), 	_T("aspect"), 	_T("assault"), 	_T("asset"), 	_T("assist"), 	_T("assume"), 	_T("asthma"), 	_T("athlete"), 	_T("atom"), 	_T("attack"), 	_T("attend"), 	_T("attitude"), 	_T("attract"), 	_T("auction"), 	_T("audit"), 	_T("august"), 	_T("aunt"), 	_T("author"), 	_T("auto"), 	_T("autumn"), 	_T("average"), 	_T("avocado"), 	_T("avoid"), 	_T("awake"), 	_T("aware"), 	_T("away"), 	_T("awesome"), 	_T("awful"), 	_T("awkward"), 	_T("axis"), 	_T("baby"), 	_T("bachelor"), 	_T("bacon"), 	_T("badge"), 	_T("bag"), 	_T("balance"), 	_T("balcony"), 	_T("ball"), 	_T("bamboo"), 	_T("banana"), 	_T("banner"), 	_T("bar"), 	_T("barely"), 	_T("bargain"), 	_T("barrel"), 	_T("base"), 	_T("basic"), 	_T("basket"), 	_T("battle"), 	_T("beach"), 	_T("bean"), 	_T("beauty"), 	_T("because"), 	_T("become"), 	_T("beef"), 	_T("before"), 	_T("begin"), 	_T("behave"), 	_T("behind"), 	_T("believe"), 	_T("below"), 	_T("belt"), 	_T("bench"), 	_T("benefit"), 	_T("best"), 	_T("betray"), 	_T("better"), 	_T("between"), 	_T("beyond"), 	_T("bicycle"), 	_T("bid"), 	_T("bike"), 	_T("bind"), 	_T("biology"), 	_T("bird"), 	_T("birth"), 	_T("bitter"), 	_T("black"), 	_T("blade"), 	_T("blame"), 	_T("blanket"), 	_T("blast"), 	_T("bleak"), 	_T("bless"), 	_T("blind"), 	_T("blood"), 	_T("blossom"), 	_T("blouse"), 	_T("blue"), 	_T("blur"), 	_T("blush"), 	_T("board"), 	_T("boat"), 	_T("body"),
};

std::vector<CString> bip39WordsPart2 = 
{
	_T("boil"), 	_T("bomb"), 	_T("bone"), 	_T("bonus"), 	_T("book"), 	_T("boost"), 	_T("border"), 	_T("boring"), 	_T("borrow"), 	_T("boss"), 	_T("bottom"), 	_T("bounce"), 	_T("box"), 	_T("boy"), 	_T("bracket"), 	_T("brain"), 	_T("brand"), 	_T("brass"), 	_T("brave"), 	_T("bread"), 	_T("breeze"), 	_T("brick"), 	_T("bridge"), 	_T("brief"), 	_T("bright"), 	_T("bring"), 	_T("brisk"), 	_T("broccoli"), 	_T("broken"), 	_T("bronze"), 	_T("broom"), 	_T("brother"), 	_T("brown"), 	_T("brush"), 	_T("bubble"), 	_T("buddy"), 	_T("budget"), 	_T("buffalo"), 	_T("build"), 	_T("bulb"), 	_T("bulk"), 	_T("bullet"), 	_T("bundle"), 	_T("bunker"), 	_T("burden"), 	_T("burger"), 	_T("burst"), 	_T("bus"), 	_T("business"), 	_T("busy"), 	_T("butter"), 	_T("buyer"), 	_T("buzz"), 	_T("cabbage"), 	_T("cabin"), 	_T("cable"), 	_T("cactus"), 	_T("cage"), 	_T("cake"), 	_T("call"), 	_T("calm"), 	_T("camera"), 	_T("camp"), 	_T("can"), 	_T("canal"), 	_T("cancel"), 	_T("candy"), 	_T("cannon"), 	_T("canoe"), 	_T("canvas"), 	_T("canyon"), 	_T("capable"), 	_T("capital"), 	_T("captain"), 	_T("car"), 	_T("carbon"), 	_T("card"), 	_T("cargo"), 	_T("carpet"), 	_T("carry"), 	_T("cart"), 	_T("case"), 	_T("cash"), 	_T("casino"), 	_T("castle"), 	_T("casual"), 	_T("cat"), 	_T("catalog"), 	_T("catch"), 	_T("category"), 	_T("cattle"), 	_T("caught"), 	_T("cause"), 	_T("caution"), 	_T("cave"), 	_T("ceiling"), 	_T("celery"), 	_T("cement"), 	_T("census"), 	_T("century"),
};

std::vector<CString> bip39WordsPart3 = 
{
	_T("cereal"), 	_T("certain"), 	_T("chair"), 	_T("chalk"), 	_T("champion"), 	_T("change"), 	_T("chaos"), 	_T("chapter"), 	_T("charge"), 	_T("chase"), 	_T("chat"), 	_T("cheap"), 	_T("check"), 	_T("cheese"), 	_T("chef"), 	_T("cherry"), 	_T("chest"), 	_T("chicken"), 	_T("chief"), 	_T("child"), 	_T("chimney"), 	_T("choice"), 	_T("choose"), 	_T("chronic"), 	_T("chuckle"), 	_T("chunk"), 	_T("churn"), 	_T("cigar"), 	_T("cinnamon"), 	_T("circle"), 	_T("citizen"), 	_T("city"), 	_T("civil"), 	_T("claim"), 	_T("clap"), 	_T("clarify"), 	_T("claw"), 	_T("clay"), 	_T("clean"), 	_T("clerk"), 	_T("clever"), 	_T("click"), 	_T("client"), 	_T("cliff"), 	_T("climb"), 	_T("clinic"), 	_T("clip"), 	_T("clock"), 	_T("clog"), 	_T("close"), 	_T("cloth"), 	_T("cloud"), 	_T("clown"), 	_T("club"), 	_T("clump"), 	_T("cluster"), 	_T("clutch"), 	_T("coach"), 	_T("coast"), 	_T("coconut"), 	_T("code"), 	_T("coffee"), 	_T("coil"), 	_T("coin"), 	_T("collect"), 	_T("color"), 	_T("column"), 	_T("combine"), 	_T("come"), 	_T("comfort"), 	_T("comic"), 	_T("common"), 	_T("company"), 	_T("concert"), 	_T("conduct"), 	_T("confirm"), 	_T("congress"), 	_T("connect"), 	_T("consider"), 	_T("control"), 	_T("convince"), 	_T("cook"), 	_T("cool"), 	_T("copper"), 	_T("copy"), 	_T("coral"), 	_T("core"), 	_T("corn"), 	_T("correct"), 	_T("cost"), 	_T("cotton"), 	_T("couch"), 	_T("country"), 	_T("couple"), 	_T("course"), 	_T("cousin"), 	_T("cover"), 	_T("coyote"), 	_T("crack"), 	_T("cradle"),
};

std::vector<CString> bip39WordsPart4 = 
{
	_T("craft"), 	_T("cram"), 	_T("crane"), 	_T("crash"), 	_T("crater"), 	_T("crawl"), 	_T("crazy"), 	_T("cream"), 	_T("credit"), 	_T("creek"), 	_T("crew"), 	_T("cricket"), 	_T("crime"), 	_T("crisp"), 	_T("critic"), 	_T("crop"), 	_T("cross"), 	_T("crouch"), 	_T("crowd"), 	_T("crucial"), 	_T("cruel"), 	_T("cruise"), 	_T("crumble"), 	_T("crunch"), 	_T("crush"), 	_T("cry"), 	_T("crystal"), 	_T("cube"), 	_T("culture"), 	_T("cup"), 	_T("cupboard"), 	_T("curious"), 	_T("current"), 	_T("curtain"), 	_T("curve"), 	_T("cushion"), 	_T("custom"), 	_T("cute"), 	_T("cycle"), 	_T("dad"), 	_T("damage"), 	_T("damp"), 	_T("dance"), 	_T("danger"), 	_T("daring"), 	_T("dash"), 	_T("daughter"), 	_T("dawn"), 	_T("day"), 	_T("deal"), 	_T("debate"), 	_T("debris"), 	_T("decade"), 	_T("december"), 	_T("decide"), 	_T("decline"), 	_T("decorate"), 	_T("decrease"), 	_T("deer"), 	_T("defense"), 	_T("define"), 	_T("defy"), 	_T("degree"), 	_T("delay"), 	_T("deliver"), 	_T("demand"), 	_T("demise"), 	_T("denial"), 	_T("dentist"), 	_T("deny"), 	_T("depart"), 	_T("depend"), 	_T("deposit"), 	_T("depth"), 	_T("deputy"), 	_T("derive"), 	_T("describe"), 	_T("desert"), 	_T("design"), 	_T("desk"), 	_T("despair"), 	_T("destroy"), 	_T("detail"), 	_T("detect"), 	_T("develop"), 	_T("device"), 	_T("devote"), 	_T("diagram"), 	_T("dial"), 	_T("diamond"), 	_T("diary"), 	_T("dice"), 	_T("diesel"), 	_T("diet"), 	_T("differ"), 	_T("digital"), 	_T("dignity"), 	_T("dilemma"), 	_T("dinner"), 	_T("dinosaur"),
};

std::vector<CString> bip39WordsPart5 = 
{
	_T("direct"), 	_T("dirt"), 	_T("disagree"), 	_T("discover"), 	_T("disease"), 	_T("dish"), 	_T("dismiss"), 	_T("disorder"), 	_T("display"), 	_T("distance"), 	_T("divert"), 	_T("divide"), 	_T("divorce"), 	_T("dizzy"), 	_T("doctor"), 	_T("document"), 	_T("dog"), 	_T("doll"), 	_T("dolphin"), 	_T("domain"), 	_T("donate"), 	_T("donkey"), 	_T("donor"), 	_T("door"), 	_T("dose"), 	_T("double"), 	_T("dove"), 	_T("draft"), 	_T("dragon"), 	_T("drama"), 	_T("drastic"), 	_T("draw"), 	_T("dream"), 	_T("dress"), 	_T("drift"), 	_T("drill"), 	_T("drink"), 	_T("drip"), 	_T("drive"), 	_T("drop"), 	_T("drum"), 	_T("dry"), 	_T("duck"), 	_T("dumb"), 	_T("dune"), 	_T("during"), 	_T("dust"), 	_T("dutch"), 	_T("duty"), 	_T("dwarf"), 	_T("dynamic"), 	_T("eager"), 	_T("eagle"), 	_T("early"), 	_T("earn"), 	_T("earth"), 	_T("easily"), 	_T("east"), 	_T("easy"), 	_T("echo"), 	_T("ecology"), 	_T("economy"), 	_T("edge"), 	_T("edit"), 	_T("educate"), 	_T("effort"), 	_T("egg"), 	_T("eight"), 	_T("either"), 	_T("elbow"), 	_T("elder"), 	_T("electric"), 	_T("elegant"), 	_T("element"), 	_T("elephant"), 	_T("elevator"), 	_T("elite"), 	_T("else"), 	_T("embark"), 	_T("embody"), 	_T("embrace"), 	_T("emerge"), 	_T("emotion"), 	_T("employ"), 	_T("empower"), 	_T("empty"), 	_T("enable"), 	_T("enact"), 	_T("end"), 	_T("endless"), 	_T("endorse"), 	_T("enemy"), 	_T("energy"), 	_T("enforce"), 	_T("engage"), 	_T("engine"), 	_T("enhance"), 	_T("enjoy"), 	_T("enlist"), 	_T("enough"),
};

std::vector<CString> bip39WordsPart6 = 
{
	_T("enrich"), 	_T("enroll"), 	_T("ensure"), 	_T("enter"), 	_T("entire"), 	_T("entry"), 	_T("envelope"), 	_T("episode"), 	_T("equal"), 	_T("equip"), 	_T("era"), 	_T("erase"), 	_T("erode"), 	_T("erosion"), 	_T("error"), 	_T("erupt"), 	_T("escape"), 	_T("essay"), 	_T("essence"), 	_T("estate"), 	_T("eternal"), 	_T("ethics"), 	_T("evidence"), 	_T("evil"), 	_T("evoke"), 	_T("evolve"), 	_T("exact"), 	_T("example"), 	_T("excess"), 	_T("exchange"), 	_T("excite"), 	_T("exclude"), 	_T("excuse"), 	_T("execute"), 	_T("exercise"), 	_T("exhaust"), 	_T("exhibit"), 	_T("exile"), 	_T("exist"), 	_T("exit"), 	_T("exotic"), 	_T("expand"), 	_T("expect"), 	_T("expire"), 	_T("explain"), 	_T("expose"), 	_T("express"), 	_T("extend"), 	_T("extra"), 	_T("eye"), 	_T("eyebrow"), 	_T("fabric"), 	_T("face"), 	_T("faculty"), 	_T("fade"), 	_T("faint"), 	_T("faith"), 	_T("fall"), 	_T("false"), 	_T("fame"), 	_T("family"), 	_T("famous"), 	_T("fan"), 	_T("fancy"), 	_T("fantasy"), 	_T("farm"), 	_T("fashion"), 	_T("fat"), 	_T("fatal"), 	_T("father"), 	_T("fatigue"), 	_T("fault"), 	_T("favorite"), 	_T("feature"), 	_T("february"), 	_T("federal"), 	_T("fee"), 	_T("feed"), 	_T("feel"), 	_T("female"), 	_T("fence"), 	_T("festival"), 	_T("fetch"), 	_T("fever"), 	_T("few"), 	_T("fiber"), 	_T("fiction"), 	_T("field"), 	_T("figure"), 	_T("file"), 	_T("film"), 	_T("filter"), 	_T("final"), 	_T("find"), 	_T("fine"), 	_T("finger"), 	_T("finish"), 	_T("fire"), 	_T("firm"), 	_T("first"),
};

std::vector<CString> bip39WordsPart7 = 
{
	_T("fiscal"), 	_T("fish"), 	_T("fit"), 	_T("fitness"), 	_T("fix"), 	_T("flag"), 	_T("flame"), 	_T("flash"), 	_T("flat"), 	_T("flavor"), 	_T("flee"), 	_T("flight"), 	_T("flip"), 	_T("float"), 	_T("flock"), 	_T("floor"), 	_T("flower"), 	_T("fluid"), 	_T("flush"), 	_T("fly"), 	_T("foam"), 	_T("focus"), 	_T("fog"), 	_T("foil"), 	_T("fold"), 	_T("follow"), 	_T("food"), 	_T("foot"), 	_T("force"), 	_T("forest"), 	_T("forget"), 	_T("fork"), 	_T("fortune"), 	_T("forum"), 	_T("forward"), 	_T("fossil"), 	_T("foster"), 	_T("found"), 	_T("fox"), 	_T("fragile"), 	_T("frame"), 	_T("frequent"), 	_T("fresh"), 	_T("friend"), 	_T("fringe"), 	_T("frog"), 	_T("front"), 	_T("frost"), 	_T("frown"), 	_T("frozen"), 	_T("fruit"), 	_T("fuel"), 	_T("fun"), 	_T("funny"), 	_T("furnace"), 	_T("fury"), 	_T("future"), 	_T("gadget"), 	_T("gain"), 	_T("galaxy"), 	_T("gallery"), 	_T("game"), 	_T("gap"), 	_T("garage"), 	_T("garbage"), 	_T("garden"), 	_T("garlic"), 	_T("garment"), 	_T("gas"), 	_T("gasp"), 	_T("gate"), 	_T("gather"), 	_T("gauge"), 	_T("gaze"), 	_T("general"), 	_T("genius"), 	_T("genre"), 	_T("gentle"), 	_T("genuine"), 	_T("gesture"), 	_T("ghost"), 	_T("giant"), 	_T("gift"), 	_T("giggle"), 	_T("ginger"), 	_T("giraffe"), 	_T("girl"), 	_T("give"), 	_T("glad"), 	_T("glance"), 	_T("glare"), 	_T("glass"), 	_T("glide"), 	_T("glimpse"), 	_T("globe"), 	_T("gloom"), 	_T("glory"), 	_T("glove"), 	_T("glow"), 	_T("glue"),
};

std::vector<CString> bip39WordsPart8 = {
	_T("goat"), 	_T("goddess"), 	_T("gold"), 	_T("good"), 	_T("goose"), 	_T("gorilla"), 	_T("gospel"), 	_T("gossip"), 	_T("govern"), 	_T("gown"), 	_T("grab"), 	_T("grace"), 	_T("grain"), 	_T("grant"), 	_T("grape"), 	_T("grass"), 	_T("gravity"), 	_T("great"), 	_T("green"), 	_T("grid"), 	_T("grief"), 	_T("grit"), 	_T("grocery"), 	_T("group"), 	_T("grow"), 	_T("grunt"), 	_T("guard"), 	_T("guess"), 	_T("guide"), 	_T("guilt"), 	_T("guitar"), 	_T("gun"), 	_T("gym"), 	_T("habit"), 	_T("hair"), 	_T("half"), 	_T("hammer"), 	_T("hamster"), 	_T("hand"), 	_T("happy"), 	_T("harbor"), 	_T("hard"), 	_T("harsh"), 	_T("harvest"), 	_T("hat"), 	_T("have"), 	_T("hawk"), 	_T("hazard"), 	_T("head"), 	_T("health"), 	_T("heart"), 	_T("heavy"), 	_T("hedgehog"), 	_T("height"), 	_T("hello"), 	_T("helmet"), 	_T("help"), 	_T("hen"), 	_T("hero"), 	_T("hidden"), 	_T("high"), 	_T("hill"), 	_T("hint"), 	_T("hip"), 	_T("hire"), 	_T("history"), 	_T("hobby"), 	_T("hockey"), 	_T("hold"), 	_T("hole"), 	_T("holiday"), 	_T("hollow"), 	_T("home"), 	_T("honey"), 	_T("hood"), 	_T("hope"), 	_T("horn"), 	_T("horror"), 	_T("horse"), 	_T("hospital"), 	_T("host"), 	_T("hotel"), 	_T("hour"), 	_T("hover"), 	_T("hub"), 	_T("huge"), 	_T("human"), 	_T("humble"), 	_T("humor"), 	_T("hundred"), 	_T("hungry"), 	_T("hunt"), 	_T("hurdle"), 	_T("hurry"), 	_T("hurt"), 	_T("husband"), 	_T("hybrid"), 	_T("ice"), 	_T("icon"), 	_T("idea"),
};

std::vector<CString> bip39WordsPart9 = 
{
	_T("identify"), 	_T("idle"), 	_T("ignore"), 	_T("ill"), 	_T("illegal"), 	_T("illness"), 	_T("image"), 	_T("imitate"), 	_T("immense"), 	_T("immune"), 	_T("impact"), 	_T("impose"), 	_T("improve"), 	_T("impulse"), 	_T("inch"), 	_T("include"), 	_T("income"), 	_T("increase"), 	_T("index"), 	_T("indicate"), 	_T("indoor"), 	_T("industry"), 	_T("infant"), 	_T("inflict"), 	_T("inform"), 	_T("inhale"), 	_T("inherit"), 	_T("initial"), 	_T("inject"), 	_T("injury"), 	_T("inmate"), 	_T("inner"), 	_T("innocent"), 	_T("input"), 	_T("inquiry"), 	_T("insane"), 	_T("insect"), 	_T("inside"), 	_T("inspire"), 	_T("install"), 	_T("intact"), 	_T("interest"), 	_T("into"), 	_T("invest"), 	_T("invite"), 	_T("involve"), 	_T("iron"), 	_T("island"), 	_T("isolate"), 	_T("issue"), 	_T("item"), 	_T("ivory"), 	_T("jacket"), 	_T("jaguar"), 	_T("jar"), 	_T("jazz"), 	_T("jealous"), 	_T("jeans"), 	_T("jelly"), 	_T("jewel"), 	_T("job"), 	_T("join"), 	_T("joke"), 	_T("journey"), 	_T("joy"), 	_T("judge"), 	_T("juice"), 	_T("jump"), 	_T("jungle"), 	_T("junior"), 	_T("junk"), 	_T("just"), 	_T("kangaroo"), 	_T("keen"), 	_T("keep"), 	_T("ketchup"), 	_T("key"), 	_T("kick"), 	_T("kid"), 	_T("kidney"), 	_T("kind"), 	_T("kingdom"), 	_T("kiss"), 	_T("kit"), 	_T("kitchen"), 	_T("kite"), 	_T("kitten"), 	_T("kiwi"), 	_T("knee"), 	_T("knife"), 	_T("knock"), 	_T("know"), 	_T("lab"), 	_T("label"), 	_T("labor"), 	_T("ladder"), 	_T("lady"), 	_T("lake"), 	_T("lamp"), 	_T("language"),
};

std::vector<CString> bip39WordsPart10 = 
{
	_T("laptop"), 	_T("large"), 	_T("later"), 	_T("latin"), 	_T("laugh"), 	_T("laundry"), 	_T("lava"), 	_T("law"), 	_T("lawn"), 	_T("lawsuit"), 	_T("layer"), 	_T("lazy"), 	_T("leader"), 	_T("leaf"), 	_T("learn"), 	_T("leave"), 	_T("lecture"), 	_T("left"), 	_T("leg"), 	_T("legal"), 	_T("legend"), 	_T("leisure"), 	_T("lemon"), 	_T("lend"), 	_T("length"), 	_T("lens"), 	_T("leopard"), 	_T("lesson"), 	_T("letter"), 	_T("level"), 	_T("liar"), 	_T("liberty"), 	_T("library"), 	_T("license"), 	_T("life"), 	_T("lift"), 	_T("light"), 	_T("like"), 	_T("limb"), 	_T("limit"), 	_T("link"), 	_T("lion"), 	_T("liquid"), 	_T("list"), 	_T("little"), 	_T("live"), 	_T("lizard"), 	_T("load"), 	_T("loan"), 	_T("lobster"), 	_T("local"), 	_T("lock"), 	_T("logic"), 	_T("lonely"), 	_T("long"), 	_T("loop"), 	_T("lottery"), 	_T("loud"), 	_T("lounge"), 	_T("love"), 	_T("loyal"), 	_T("lucky"), 	_T("luggage"), 	_T("lumber"), 	_T("lunar"), 	_T("lunch"), 	_T("luxury"), 	_T("lyrics"), 	_T("machine"), 	_T("mad"), 	_T("magic"), 	_T("magnet"), 	_T("maid"), 	_T("mail"), 	_T("main"), 	_T("major"), 	_T("make"), 	_T("mammal"), 	_T("man"), 	_T("manage"), 	_T("mandate"), 	_T("mango"), 	_T("mansion"), 	_T("manual"), 	_T("maple"), 	_T("marble"), 	_T("march"), 	_T("margin"), 	_T("marine"), 	_T("market"), 	_T("marriage"), 	_T("mask"), 	_T("mass"), 	_T("master"), 	_T("match"), 	_T("material"), 	_T("math"), 	_T("matrix"), 	_T("matter"), 	_T("maximum"),
};

std::vector<CString> bip39WordsPart11 = 
{
	_T("maze"), 	_T("meadow"), 	_T("mean"), 	_T("measure"), 	_T("meat"), 	_T("mechanic"), 	_T("medal"), 	_T("media"), 	_T("melody"), 	_T("melt"), 	_T("member"), 	_T("memory"), 	_T("mention"), 	_T("menu"), 	_T("mercy"), 	_T("merge"), 	_T("merit"), 	_T("merry"), 	_T("mesh"), 	_T("message"), 	_T("metal"), 	_T("method"), 	_T("middle"), 	_T("midnight"), 	_T("milk"), 	_T("million"), 	_T("mimic"), 	_T("mind"), 	_T("minimum"), 	_T("minor"), 	_T("minute"), 	_T("miracle"), 	_T("mirror"), 	_T("misery"), 	_T("miss"), 	_T("mistake"), 	_T("mix"), 	_T("mixed"), 	_T("mixture"), 	_T("mobile"), 	_T("model"), 	_T("modify"), 	_T("mom"), 	_T("moment"), 	_T("monitor"), 	_T("monkey"), 	_T("monster"), 	_T("month"), 	_T("moon"), 	_T("moral"), 	_T("more"), 	_T("morning"), 	_T("mosquito"), 	_T("mother"), 	_T("motion"), 	_T("motor"), 	_T("mountain"), 	_T("mouse"), 	_T("move"), 	_T("movie"), 	_T("much"), 	_T("muffin"), 	_T("mule"), 	_T("multiply"), 	_T("muscle"), 	_T("museum"), 	_T("mushroom"), 	_T("music"), 	_T("must"), 	_T("mutual"), 	_T("myself"), 	_T("mystery"), 	_T("myth"), 	_T("naive"), 	_T("name"), 	_T("napkin"), 	_T("narrow"), 	_T("nasty"), 	_T("nation"), 	_T("nature"), 	_T("near"), 	_T("neck"), 	_T("need"), 	_T("negative"), 	_T("neglect"), 	_T("neither"), 	_T("nephew"), 	_T("nerve"), 	_T("nest"), 	_T("net"), 	_T("network"), 	_T("neutral"), 	_T("never"), 	_T("news"), 	_T("next"), 	_T("nice"), 	_T("night"), 	_T("noble"), 	_T("noise"), 	_T("nominee"),
};

std::vector<CString> bip39WordsPart12 = 
{
	_T("noodle"), 	_T("normal"), 	_T("north"), 	_T("nose"), 	_T("notable"), 	_T("note"), 	_T("nothing"), 	_T("notice"), 	_T("novel"), 	_T("now"), 	_T("nuclear"), 	_T("number"), 	_T("nurse"), 	_T("nut"), 	_T("oak"), 	_T("obey"), 	_T("object"), 	_T("oblige"), 	_T("obscure"), 	_T("observe"), 	_T("obtain"), 	_T("obvious"), 	_T("occur"), 	_T("ocean"), 	_T("october"), 	_T("odor"), 	_T("off"), 	_T("offer"), 	_T("office"), 	_T("often"), 	_T("oil"), 	_T("okay"), 	_T("old"), 	_T("olive"), 	_T("olympic"), 	_T("omit"), 	_T("once"), 	_T("one"), 	_T("onion"), 	_T("online"), 	_T("only"), 	_T("open"), 	_T("opera"), 	_T("opinion"), 	_T("oppose"), 	_T("option"), 	_T("orange"), 	_T("orbit"), 	_T("orchard"), 	_T("order"), 	_T("ordinary"), 	_T("organ"), 	_T("orient"), 	_T("original"), 	_T("orphan"), 	_T("ostrich"), 	_T("other"), 	_T("outdoor"), 	_T("outer"), 	_T("output"), 	_T("outside"), 	_T("oval"), 	_T("oven"), 	_T("over"), 	_T("own"), 	_T("owner"), 	_T("oxygen"), 	_T("oyster"), 	_T("ozone"), 	_T("pact"), 	_T("paddle"), 	_T("page"), 	_T("pair"), 	_T("palace"), 	_T("palm"), 	_T("panda"), 	_T("panel"), 	_T("panic"), 	_T("panther"), 	_T("paper"), 	_T("parade"), 	_T("parent"), 	_T("park"), 	_T("parrot"), 	_T("party"), 	_T("pass"), 	_T("patch"), 	_T("path"), 	_T("patient"), 	_T("patrol"), 	_T("pattern"), 	_T("pause"), 	_T("pave"), 	_T("payment"), 	_T("peace"), 	_T("peanut"), 	_T("pear"), 	_T("peasant"), 	_T("pelican"), 	_T("pen"),
};

std::vector<CString> bip39WordsPart13 = 
{
	_T("penalty"), 	_T("pencil"), 	_T("people"), 	_T("pepper"), 	_T("perfect"), 	_T("permit"), 	_T("person"), 	_T("pet"), 	_T("phone"), 	_T("photo"), 	_T("phrase"), 	_T("physical"), 	_T("piano"), 	_T("picnic"), 	_T("picture"), 	_T("piece"), 	_T("pig"), 	_T("pigeon"), 	_T("pill"), 	_T("pilot"), 	_T("pink"), 	_T("pioneer"), 	_T("pipe"), 	_T("pistol"), 	_T("pitch"), 	_T("pizza"), 	_T("place"), 	_T("planet"), 	_T("plastic"), 	_T("plate"), 	_T("play"), 	_T("please"), 	_T("pledge"), 	_T("pluck"), 	_T("plug"), 	_T("plunge"), 	_T("poem"), 	_T("poet"), 	_T("point"), 	_T("polar"), 	_T("pole"), 	_T("police"), 	_T("pond"), 	_T("pony"), 	_T("pool"), 	_T("popular"), 	_T("portion"), 	_T("position"), 	_T("possible"), 	_T("post"), 	_T("potato"), 	_T("pottery"), 	_T("poverty"), 	_T("powder"), 	_T("power"), 	_T("practice"), 	_T("praise"), 	_T("predict"), 	_T("prefer"), 	_T("prepare"), 	_T("present"), 	_T("pretty"), 	_T("prevent"), 	_T("price"), 	_T("pride"), 	_T("primary"), 	_T("print"), 	_T("priority"), 	_T("prison"), 	_T("private"), 	_T("prize"), 	_T("problem"), 	_T("process"), 	_T("produce"), 	_T("profit"), 	_T("program"), 	_T("project"), 	_T("promote"), 	_T("proof"), 	_T("property"), 	_T("prosper"), 	_T("protect"), 	_T("proud"), 	_T("provide"), 	_T("public"), 	_T("pudding"), 	_T("pull"), 	_T("pulp"), 	_T("pulse"), 	_T("pumpkin"), 	_T("punch"), 	_T("pupil"), 	_T("puppy"), 	_T("purchase"), 	_T("purity"), 	_T("purpose"), 	_T("purse"), 	_T("push"), 	_T("put"), 	_T("puzzle"),
};

std::vector<CString> bip39WordsPart14 = 
{
	_T("pyramid"), 	_T("quality"), 	_T("quantum"), 	_T("quarter"), 	_T("question"), 	_T("quick"), 	_T("quit"), 	_T("quiz"), 	_T("quote"), 	_T("rabbit"), 	_T("raccoon"), 	_T("race"), 	_T("rack"), 	_T("radar"), 	_T("radio"), 	_T("rail"), 	_T("rain"), 	_T("raise"), 	_T("rally"), 	_T("ramp"), 	_T("ranch"), 	_T("random"), 	_T("range"), 	_T("rapid"), 	_T("rare"), 	_T("rate"), 	_T("rather"), 	_T("raven"), 	_T("raw"), 	_T("razor"), 	_T("ready"), 	_T("real"), 	_T("reason"), 	_T("rebel"), 	_T("rebuild"), 	_T("recall"), 	_T("receive"), 	_T("recipe"), 	_T("record"), 	_T("recycle"), 	_T("reduce"), 	_T("reflect"), 	_T("reform"), 	_T("refuse"), 	_T("region"), 	_T("regret"), 	_T("regular"), 	_T("reject"), 	_T("relax"), 	_T("release"), 	_T("relief"), 	_T("rely"), 	_T("remain"), 	_T("remember"), 	_T("remind"), 	_T("remove"), 	_T("render"), 	_T("renew"), 	_T("rent"), 	_T("reopen"), 	_T("repair"), 	_T("repeat"), 	_T("replace"), 	_T("report"), 	_T("require"), 	_T("rescue"), 	_T("resemble"), 	_T("resist"), 	_T("resource"), 	_T("response"), 	_T("result"), 	_T("retire"), 	_T("retreat"), 	_T("return"), 	_T("reunion"), 	_T("reveal"), 	_T("review"), 	_T("reward"), 	_T("rhythm"), 	_T("rib"), 	_T("ribbon"), 	_T("rice"), 	_T("rich"), 	_T("ride"), 	_T("ridge"), 	_T("rifle"), 	_T("right"), 	_T("rigid"), 	_T("ring"), 	_T("riot"), 	_T("ripple"), 	_T("risk"), 	_T("ritual"), 	_T("rival"), 	_T("river"), 	_T("road"), 	_T("roast"), 	_T("robot"), 	_T("robust"), 	_T("rocket"),
};

std::vector<CString> bip39WordsPart15 = 
{
	_T("romance"), 	_T("roof"), 	_T("rookie"), 	_T("room"), 	_T("rose"), 	_T("rotate"), 	_T("rough"), 	_T("round"), 	_T("route"), 	_T("royal"), 	_T("rubber"), 	_T("rude"), 	_T("rug"), 	_T("rule"), 	_T("run"), 	_T("runway"), 	_T("rural"), 	_T("sad"), 	_T("saddle"), 	_T("sadness"), 	_T("safe"), 	_T("sail"), 	_T("salad"), 	_T("salmon"), 	_T("salon"), 	_T("salt"), 	_T("salute"), 	_T("same"), 	_T("sample"), 	_T("sand"), 	_T("satisfy"), 	_T("satoshi"), 	_T("sauce"), 	_T("sausage"), 	_T("save"), 	_T("say"), 	_T("scale"), 	_T("scan"), 	_T("scare"), 	_T("scatter"), 	_T("scene"), 	_T("scheme"), 	_T("school"), 	_T("science"), 	_T("scissors"), 	_T("scorpion"), 	_T("scout"), 	_T("scrap"), 	_T("screen"), 	_T("script"), 	_T("scrub"), 	_T("sea"), 	_T("search"), 	_T("season"), 	_T("seat"), 	_T("second"), 	_T("secret"), 	_T("section"), 	_T("security"), 	_T("seed"), 	_T("seek"), 	_T("segment"), 	_T("select"), 	_T("sell"), 	_T("seminar"), 	_T("senior"), 	_T("sense"), 	_T("sentence"), 	_T("series"), 	_T("service"), 	_T("session"), 	_T("settle"), 	_T("setup"), 	_T("seven"), 	_T("shadow"), 	_T("shaft"), 	_T("shallow"), 	_T("share"), 	_T("shed"), 	_T("shell"), 	_T("sheriff"), 	_T("shield"), 	_T("shift"), 	_T("shine"), 	_T("ship"), 	_T("shiver"), 	_T("shock"), 	_T("shoe"), 	_T("shoot"), 	_T("shop"), 	_T("short"), 	_T("shoulder"), 	_T("shove"), 	_T("shrimp"), 	_T("shrug"), 	_T("shuffle"), 	_T("shy"), 	_T("sibling"), 	_T("sick"), 	_T("side"),
};

std::vector<CString> bip39WordsPart16 = 
{
	_T("siege"), 	_T("sight"), 	_T("sign"), 	_T("silent"), 	_T("silk"), 	_T("silly"), 	_T("silver"), 	_T("similar"), 	_T("simple"), 	_T("since"), 	_T("sing"), 	_T("siren"), 	_T("sister"), 	_T("situate"), 	_T("six"), 	_T("size"), 	_T("skate"), 	_T("sketch"), 	_T("ski"), 	_T("skill"), 	_T("skin"), 	_T("skirt"), 	_T("skull"), 	_T("slab"), 	_T("slam"), 	_T("sleep"), 	_T("slender"), 	_T("slice"), 	_T("slide"), 	_T("slight"), 	_T("slim"), 	_T("slogan"), 	_T("slot"), 	_T("slow"), 	_T("slush"), 	_T("small"), 	_T("smart"), 	_T("smile"), 	_T("smoke"), 	_T("smooth"), 	_T("snack"), 	_T("snake"), 	_T("snap"), 	_T("sniff"), 	_T("snow"), 	_T("soap"), 	_T("soccer"), 	_T("social"), 	_T("sock"), 	_T("soda"), 	_T("soft"), 	_T("solar"), 	_T("soldier"), 	_T("solid"), 	_T("solution"), 	_T("solve"), 	_T("someone"), 	_T("song"), 	_T("soon"), 	_T("sorry"), 	_T("sort"), 	_T("soul"), 	_T("sound"), 	_T("soup"), 	_T("source"), 	_T("south"), 	_T("space"), 	_T("spare"), 	_T("spatial"), 	_T("spawn"), 	_T("speak"), 	_T("special"), 	_T("speed"), 	_T("spell"), 	_T("spend"), 	_T("sphere"), 	_T("spice"), 	_T("spider"), 	_T("spike"), 	_T("spin"), 	_T("spirit"), 	_T("split"), 	_T("spoil"), 	_T("sponsor"), 	_T("spoon"), 	_T("sport"), 	_T("spot"), 	_T("spray"), 	_T("spread"), 	_T("spring"), 	_T("spy"), 	_T("square"), 	_T("squeeze"), 	_T("squirrel"), 	_T("stable"), 	_T("stadium"), 	_T("staff"), 	_T("stage"), 	_T("stairs"), 	_T("stamp"),
};

std::vector<CString> bip39WordsPart17 = 
{
	_T("stand"), 	_T("start"), 	_T("state"), 	_T("stay"), 	_T("steak"), 	_T("steel"), 	_T("stem"), 	_T("step"), 	_T("stereo"), 	_T("stick"), 	_T("still"), 	_T("sting"), 	_T("stock"), 	_T("stomach"), 	_T("stone"), 	_T("stool"), 	_T("story"), 	_T("stove"), 	_T("strategy"), 	_T("street"), 	_T("strike"), 	_T("strong"), 	_T("struggle"), 	_T("student"), 	_T("stuff"), 	_T("stumble"), 	_T("style"), 	_T("subject"), 	_T("submit"), 	_T("subway"), 	_T("success"), 	_T("such"), 	_T("sudden"), 	_T("suffer"), 	_T("sugar"), 	_T("suggest"), 	_T("suit"), 	_T("summer"), 	_T("sun"), 	_T("sunny"), 	_T("sunset"), 	_T("super"), 	_T("supply"), 	_T("supreme"), 	_T("sure"), 	_T("surface"), 	_T("surge"), 	_T("surprise"), 	_T("surround"), 	_T("survey"), 	_T("suspect"), 	_T("sustain"), 	_T("swallow"), 	_T("swamp"), 	_T("swap"), 	_T("swarm"), 	_T("swear"), 	_T("sweet"), 	_T("swift"), 	_T("swim"), 	_T("swing"), 	_T("switch"), 	_T("sword"), 	_T("symbol"), 	_T("symptom"), 	_T("syrup"), 	_T("system"), 	_T("table"), 	_T("tackle"), 	_T("tag"), 	_T("tail"), 	_T("talent"), 	_T("talk"), 	_T("tank"), 	_T("tape"), 	_T("target"), 	_T("task"), 	_T("taste"), 	_T("tattoo"), 	_T("taxi"), 	_T("teach"), 	_T("team"), 	_T("tell"), 	_T("ten"), 	_T("tenant"), 	_T("tennis"), 	_T("tent"), 	_T("term"), 	_T("test"), 	_T("text"), 	_T("thank"), 	_T("that"), 	_T("theme"), 	_T("then"), 	_T("theory"), 	_T("there"), 	_T("they"), 	_T("thing"), 	_T("this"), 	_T("thought"),
};

std::vector<CString> bip39WordsPart18 = 
{
	_T("three"), 	_T("thrive"), 	_T("throw"), 	_T("thumb"), 	_T("thunder"), 	_T("ticket"), 	_T("tide"), 	_T("tiger"), 	_T("tilt"), 	_T("timber"), 	_T("time"), 	_T("tiny"), 	_T("tip"), 	_T("tired"), 	_T("tissue"), 	_T("title"), 	_T("toast"), 	_T("tobacco"), 	_T("today"), 	_T("toddler"), 	_T("toe"), 	_T("together"), 	_T("toilet"), 	_T("token"), 	_T("tomato"), 	_T("tomorrow"), 	_T("tone"), 	_T("tongue"), 	_T("tonight"), 	_T("tool"), 	_T("tooth"), 	_T("top"), 	_T("topic"), 	_T("topple"), 	_T("torch"), 	_T("tornado"), 	_T("tortoise"), 	_T("toss"), 	_T("total"), 	_T("tourist"), 	_T("toward"), 	_T("tower"), 	_T("town"), 	_T("toy"), 	_T("track"), 	_T("trade"), 	_T("traffic"), 	_T("tragic"), 	_T("train"), 	_T("transfer"), 	_T("trap"), 	_T("trash"), 	_T("travel"), 	_T("tray"), 	_T("treat"), 	_T("tree"), 	_T("trend"), 	_T("trial"), 	_T("tribe"), 	_T("trick"), 	_T("trigger"), 	_T("trim"), 	_T("trip"), 	_T("trophy"), 	_T("trouble"), 	_T("truck"), 	_T("true"), 	_T("truly"), 	_T("trumpet"), 	_T("trust"), 	_T("truth"), 	_T("try"), 	_T("tube"), 	_T("tuition"), 	_T("tumble"), 	_T("tuna"), 	_T("tunnel"), 	_T("turkey"), 	_T("turn"), 	_T("turtle"), 	_T("twelve"), 	_T("twenty"), 	_T("twice"), 	_T("twin"), 	_T("twist"), 	_T("two"), 	_T("type"), 	_T("typical"), 	_T("ugly"), 	_T("umbrella"), 	_T("unable"), 	_T("unaware"), 	_T("uncle"), 	_T("uncover"), 	_T("under"), 	_T("undo"), 	_T("unfair"), 	_T("unfold"), 	_T("unhappy"), 	_T("uniform"),
};

std::vector<CString> bip39WordsPart19 = 
{
	_T("unique"), 	_T("unit"), 	_T("universe"), 	_T("unknown"), 	_T("unlock"), 	_T("until"), 	_T("unusual"), 	_T("unveil"), 	_T("update"), 	_T("upgrade"), 	_T("uphold"), 	_T("upon"), 	_T("upper"), 	_T("upset"), 	_T("urban"), 	_T("urge"), 	_T("usage"), 	_T("use"), 	_T("used"), 	_T("useful"), 	_T("useless"), 	_T("usual"), 	_T("utility"), 	_T("vacant"), 	_T("vacuum"), 	_T("vague"), 	_T("valid"), 	_T("valley"), 	_T("valve"), 	_T("van"), 	_T("vanish"), 	_T("vapor"), 	_T("various"), 	_T("vast"), 	_T("vault"), 	_T("vehicle"), 	_T("velvet"), 	_T("vendor"), 	_T("venture"), 	_T("venue"), 	_T("verb"), 	_T("verify"), 	_T("version"), 	_T("very"), 	_T("vessel"), 	_T("veteran"), 	_T("viable"), 	_T("vibrant"), 	_T("vicious"), 	_T("victory"), 	_T("video"), 	_T("view"), 	_T("village"), 	_T("vintage"), 	_T("violin"), 	_T("virtual"), 	_T("virus"), 	_T("visa"), 	_T("visit"), 	_T("visual"), 	_T("vital"), 	_T("vivid"), 	_T("vocal"), 	_T("voice"), 	_T("void"), 	_T("volcano"), 	_T("volume"), 	_T("vote"), 	_T("voyage"), 	_T("wage"), 	_T("wagon"), 	_T("wait"), 	_T("walk"), 	_T("wall"), 	_T("walnut"), 	_T("want"), 	_T("warfare"), 	_T("warm"), 	_T("warrior"), 	_T("wash"), 	_T("wasp"), 	_T("waste"), 	_T("water"), 	_T("wave"), 	_T("way"), 	_T("wealth"), 	_T("weapon"), 	_T("wear"), 	_T("weasel"), 	_T("weather"), 	_T("web"), 	_T("wedding"), 	_T("weekend"), 	_T("weird"), 	_T("welcome"), 	_T("west"), 	_T("wet"), 	_T("whale"), 	_T("what"), 	_T("wheat"),
};

std::vector<CString> bip39WordsPart20 = 
{
	_T("wheel"), 	_T("when"), 	_T("where"), 	_T("whip"), 	_T("whisper"), 	_T("wide"), 	_T("width"), 	_T("wife"), 	_T("wild"), 	_T("will"), 	_T("win"), 	_T("window"), 	_T("wine"), 	_T("wing"), 	_T("wink"), 	_T("winner"), 	_T("winter"), 	_T("wire"), 	_T("wisdom"), 	_T("wise"), 	_T("wish"), 	_T("witness"), 	_T("wolf"), 	_T("woman"), 	_T("wonder"), 	_T("wood"), 	_T("wool"), 	_T("word"), 	_T("work"), 	_T("world"), 	_T("worry"), 	_T("worth"), 	_T("wrap"), 	_T("wreck"), 	_T("wrestle"), 	_T("wrist"), 	_T("write"), 	_T("wrong"), 	_T("yard"), 	_T("year"), 	_T("yellow"), 	_T("you"), 	_T("young"), 	_T("youth"), 	_T("zebra"), 	_T("zero"), 	_T("zone"), 	_T("zoo"),
};

BOOL CBip39FinderDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// Set the icon for this dialog.  The framework does this automatically
	//  when the application's main window is not a dialog
	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon

	// Concatenate the generated vectors
	bip39Words.insert(bip39Words.end(), bip39WordsPart0.begin(), bip39WordsPart0.end());
	bip39Words.insert(bip39Words.end(), bip39WordsPart1.begin(), bip39WordsPart1.end());
	bip39Words.insert(bip39Words.end(), bip39WordsPart2.begin(), bip39WordsPart2.end());
	bip39Words.insert(bip39Words.end(), bip39WordsPart3.begin(), bip39WordsPart3.end());
	bip39Words.insert(bip39Words.end(), bip39WordsPart4.begin(), bip39WordsPart4.end());
	bip39Words.insert(bip39Words.end(), bip39WordsPart5.begin(), bip39WordsPart5.end());
	bip39Words.insert(bip39Words.end(), bip39WordsPart6.begin(), bip39WordsPart6.end());
	bip39Words.insert(bip39Words.end(), bip39WordsPart7.begin(), bip39WordsPart7.end());
	bip39Words.insert(bip39Words.end(), bip39WordsPart8.begin(), bip39WordsPart8.end());
	bip39Words.insert(bip39Words.end(), bip39WordsPart9.begin(), bip39WordsPart9.end());
	bip39Words.insert(bip39Words.end(), bip39WordsPart10.begin(), bip39WordsPart10.end());
	bip39Words.insert(bip39Words.end(), bip39WordsPart11.begin(), bip39WordsPart11.end());
	bip39Words.insert(bip39Words.end(), bip39WordsPart12.begin(), bip39WordsPart12.end());
	bip39Words.insert(bip39Words.end(), bip39WordsPart13.begin(), bip39WordsPart13.end());
	bip39Words.insert(bip39Words.end(), bip39WordsPart14.begin(), bip39WordsPart14.end());
	bip39Words.insert(bip39Words.end(), bip39WordsPart15.begin(), bip39WordsPart15.end());
	bip39Words.insert(bip39Words.end(), bip39WordsPart16.begin(), bip39WordsPart16.end());
	bip39Words.insert(bip39Words.end(), bip39WordsPart17.begin(), bip39WordsPart17.end());
	bip39Words.insert(bip39Words.end(), bip39WordsPart18.begin(), bip39WordsPart18.end());
	bip39Words.insert(bip39Words.end(), bip39WordsPart19.begin(), bip39WordsPart19.end());
	bip39Words.insert(bip39Words.end(), bip39WordsPart20.begin(), bip39WordsPart20.end());
	// Post a custom message to handle after initialization
	SetTimer(1, 100, NULL);  // Timer ID 1, 
	return TRUE;  // return TRUE  unless you set the focus to a control
}
LRESULT CBip39FinderDlg::OnPostInit(WPARAM wParam, LPARAM lParam)
{
	// Set the input focus to your control
	GotoDlgCtrl(GetDlgItem(IDC_EDIT_INPUT));
	return 0;
}
void CBip39FinderDlg::OnEnChangeEditInput()
{
	CString filter;
	m_editInput.GetWindowTextW(filter);
	UpdateWordList(filter);
}

void CBip39FinderDlg::UpdateWordList(const CString& filter)
{
	m_listWords.ResetContent();

	if (filter.IsEmpty()) return;

	// Convert the filter to a regex pattern
	std::wstring pattern = (LPCTSTR)filter;
	std::replace(pattern.begin(), pattern.end(), L'?', L'.');
	size_t pos = 0;
	while ((pos = pattern.find(L'*', pos)) != std::wstring::npos) 
	{
		pattern.replace(pos, 1, L".*");
		pos += 2; // Move past the ".*"
	}
	int wordCount = 0; // Counter for the number of words found
	try 
	{
		std::wregex regexPattern(pattern, std::regex_constants::icase); // Case-insensitive search

		for (const CString& word : bip39Words)
		{
			if (std::regex_search((LPCTSTR)word, regexPattern))
			{
				m_listWords.AddString(word);
				wordCount++;
			}
		}
		// Update the static control (label) with the number of words found
		CString label;
		label.Format(_T("%d words found"), wordCount);
		SetDlgItemText(IDC_STATIC_WORDS_FOUND, label);
	}
	catch (const std::regex_error&) 
	{
		// Handle regex errors (e.g., if the user enters an invalid pattern)
		// For now, we'll simply ignore them.
	}
}
