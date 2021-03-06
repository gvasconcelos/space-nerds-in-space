#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#include "mtwist.h"
#include "infinite-taunt.h"

static char *nothing = "";

static char *You[] = {
	"you",
	"your pilot",
	"your technology",
	"your mother",
	"your father",
	"your engineer",
	"your weapons officer",
	"your scientist",
	"you humans",
	"your sister",
	"your captain",
	"your navigator",
	"your spaceship",
	"your gamete donors",
	"your species",
	"your culture", 
	"your grandmother", 
	"your grandfather", 
	"your wife", 
	"the mother of your hatchlings", 
	"the father of your hatchlings", 
	"your mama", 
	"your mama", 
	"your garbage scow",
	"your brood of hatchlings",
	"you meatbags",
	"you meat robots",
	"you organic droids",
	"your hatchlings",
	"your spacefaring scrap heap",
	"your spacegoing garbage heap",
	"your spacefaring contraption",
};

static char *Are[] = {
	"are",
	"is",
	"be",
	"are being",
	"was",
	"are one of those",
};

static char *Action[] = {
	"drive",
	"pilot",
	"shoot",
	"fire torpedoes",
	"fire phasers",
	"weild phasers",
	"aim",
	"smell",
	"fart",
	"fail",
	"will fail",
	"will not succeed",
	"embarasses me",
	"will cry",
	"taste",
	"will beg for mercy",
	"cry",
	"run away",
	"does not succeed",
	"fails to succeed",
	"performs unacceptably",
	"performs inadequately",
	"fails to perform acceptably",
	"fails to perform adequately",
	"severely underperforms and",
	"achieve negative success",
	"reailizes failure",
	"exist",
	"communicates",
	"walks",
	"talks",
	"eats",
	"drinks",
	"thinks",
	"cogitates",
	"snorks",
	"swoggs",
	"kniddles",
	"kones",
	"drools",
	"twitches",
	"will burn",
	"will be destroyed",
	"will be blasted",
	"will be annihilated",
	"will be terminated",
	"will be enzarked",
	"will be engorfed",
	"are dishonest",
	"tell lies",
	"make me sick",
	"disgusts",
	"offends",
	"sucks",
	"emits fumes",
	"leaks fluids",
	"looks",
};

static char *Like[] = {
	"like",
	"similar to",
	"in the manner of",
	"in a way that reminds me of",
	"in a way that recalls",
	"as though emulating",
	"resembling",
	"just like",	
	"exactly like",
	"as",
	"as if he is",
	"as if she is",
	"comparable to",
	"worse than",
	"even worse than",
	"almost as bad as",
	"as badly as",
	"in a manner that exceeds in poor quality even",
	"like it is always as bad as",
	"is as terrible as",
	"is as terrible as",
	"is as incompetent as",
	"is as unschooled as",
	"is as inproficient as",
	"as awful as",
	"as horrible as",
	"as torkulant as",
	"as gonky as",
	"as durtinous as",
	"more rotten than",
	"more disgusting than",
};
	

static char *Adjective[] = {
	"drunken",
	"wasted",
	"emboozled",
	"addled",
	"crazy",
	"insane",
	"froomy",
	"borgulent",
	"flatulent",
	"gas-filled",
	"odorous",
	"noxious",
	"fuming",
	"smelly",
	"farty",
	"over inflated",
	"reeking",
	"stinky",
	"sweaty",
	"greasy",
	"antique",
	"ancient",
	"bipedal",
	"pathetic",
	"pitiful",
	"disgusting",
	"repellant",
	"orgnacious",
	"redognant",
	"unintelligent",
	"stupid",
	"idiotic",
	"scorched",
	"orbular",
	"spherical",
	"toothless",
	"mostly harmless",
	"de-clawed",
	"scrambled",
	"wounded",
	"halfwit",
	"brain damaged",
	"half brained",
	"intoxicated",
	"sedated",
	"sleepy",
	"useless",
	"broken",
	"out of order",
	"borked",
	"fractured",
	"cromulent",
	"blasted",
	"earth-schooled",
	"ignorant",
	"backwater",
	"uneducated",
	"earthman",
	"loaded",
	"fried",
	"high",
	"stoned",
	"sleeping",
	"half-conscious",
	"robotic",
	"droidly",
	"malfunctioning",
	"stunned",
	"beheaded",
	"lobotomized",
	"angry",
	"furious",
	"enraged",
	"frightened",
	"scared",
	"timid",
	"terrified",
	"startled",
	"rotten",
	"crying",
	"decayed",
	"old",
	"slime covered",
	"slime encrusted",
	"slimy",
	"bug infested",
	};

static char *Nationality[] = {
	"Vogon",
	"Nowwhattian",
	"Huttian",
	"Frubian",
	"Wallunian",
	"Hybonian",
	"Purkrani",
	"Furtian",
	"Barkonian",
	"Schaazbaut",
	"Albonian",
	"Neruvian",
	"Skonkulan",
	"Byntian",
	"Zurtian",
	"Tralfamadorian",
	"Traalian",
	"Earthling",
	"Arcturan",
	"Deneban",
	"Cepheid",
	"Kastran",
	"Nekkari",
	"Okulan",
	"Okulan",
	"Vegan",
	"Vegan",
	"Zosmani",
	"Rigelian",
	"Solian",
	"Fractulan",
	"Porgacine",
	"Nurtian",
	"Cappellan",
};

static char *Beast[] = {
	"lizard",
	"snake",
	"eel",
	"boghog",
	"horkbeast",
	"jebbok",
	"gervuza",
	"beast",
	"cow",
	"toad",
	"mushroom",
	"pigdog",
	"dog",
	"pig",
	"zorb",
	"slug",
	"turtle",
	"tortoise",
	"mollusc",
	"tuber",
	"vegetable",
	"turnip",
	"tentacle beast",
	"toilet",
	"waste disposal unit",
	"garbage heap",
	"waste digester",
	"waste organism",
	"sewage eater",
	"computer",
	"iceborer",
	"pustule",
	"witch doctor",
	"fortune teller",
	"space priest",
	"space pirate",
	"space hobo",
	"space vagrant",
	"space bum",
	"space butt",
	"space slug",
	"space beetle",
	"beetle",
	"snaprat",
	"vornalox",
	"porridge",
	"cabbage",
	"egg capsule",
	"teabags",
	"muskbats",
	"machinery",
	"deceleraptor",
	"space wanker",
	"space punk",
	"space ruffian",
	"melonhead",
	"rock dweller",
	"asteroid miner",
	"outer planet dweller",
	"garbage dweller",
	"buttless normal"
};

static char *Bad_thing[] = {
	"moron",
	"butthead",
	"buttface",
	"butt crack",
	"idiot",
	"fool",
	"joke",
	"space garbage",
	"rocks for brains",
	"Borgon",
	"simpleton",	
	"outer rim planet dweller",
	"Terran",
	"Earthling",
	"crazy Kroznor",
	"dogulent dog",
	"horkbeast",
	"wormatozoa",
	"skuggulorp",
	"forpulous driggotron",
	"space refuse",
	"ejected garbage capsule",
	"dung beast",
	"source of stink",
	"stinkbeast larvae",
	"vornalox eggs",
	"olfactory offender",
	"nobbett seed",
	"horkbeast seed",
	"artist",
};

static char *Known_For[] = {
	"is known for",
	"is renowned for",
	"has a reputation for",
	"is celebrated for",
	"is lauded for",
	"is widely known for",
	"is fabled for",
	"is famous for",
	"is most famous for",
	"is famed for",
	"is infamous for",
	"is legendary for",
	"is highly regarded for",
	"enjoys a reputation for",
	"is responsible for",
	"is notable for",
	"is most notable for",
	"is noted for",
	"is recognized for",
	"is feared for",
	"is beloved for",
};

static char *Producing[] = {
	"supplying",
	"being a source of",
	"producing",
	"exporting",
	"manufacturing",
	"creating",
	"fabricating",
	"constructing",
	"making",
	"shipping",
	"transporting",
	"reselling",
	"selling",
};

static char *Exceptional[] = {
	"exceptional",
	"fearsome",
	"fine",
	"wonderful",
	"great",
	"exciting",
	"exhilarating",
	"awesome",
	"astounding",
	"astonishing",
	"top flight",
	"the best",
	"ridiculously good",
	"amazing",
	"fantastic",
	"improbable",
	"fanciful",
	"comical",
	"unlikely",
	"really great",
	"very good",
	"good",
	"superb",
	"excellent",
	"good quality",
	"exceptionally good",
	"high quality",
	"top notch",
	"top shelf",
	"exceedingly good",
	"frighteningly good",
	"really excellent",
	"top of the line",
	"first class",
	"outstanding",
	"best of class",
	"state of the art",
	"staggering",
	"stupendous",
	"stunning",
	"breathtaking",
	"scandalous",
	"magnificent",
	"flawless",
	"phenomenal",
	"remarkable",
	"marvelous",
	"transcendant",
	"complicated",
	"complex",
	"stellar",
};

static char *Avoid[] = {
	"avoid",
	"skip",
	"don't bother with",
	"resist",
	"shun",
	"stay away from",
	"steer clear of",
	"evade",
	"eschew",
	"abstain from",
	"bypass",
	"dodge",
};

static char *Terrible[] = {
	"awful",
	"incomprehensible",
	"mediocre",
	"sub par",
	"deficient",
	"defective",
	"damaged",
	"insipid",
	"suspect",
	"sketchy",
	"borderline",
	"terrible",
	"worthless",
	"wretched",
	"shameful",
	"bad",
	"poor",
	"poor quality",
	"regrettable",
	"less than stellar",
	"painful",
	"dreadful",
	"boring",
	"tepid",
	"banal",
	"disgusting",
	"icky",
	"loathesome",
	"tedious",
	"pretentious",
	"revolting",
	"terrifying",
	"poisonous",
	"noxious",
	"horrifying",
	"egregious",
	"lame",
	"scandalous",
	"embarassing",
	"disenchanting",
	"underwhelming",
	"crappy",
	"shoddy",
	"disappointing",
};

static char *Product[] = {
	"weapons",
	"hand weapons",
	"textiles",
	"recreational drugs of various types",
	"dilithium crystals",
	"iron",
	"tax preparation software",
	"encryption algorithms",
	"sporting goods",
	"cylindric diamacron",
	"styrofoam cups",
	"coal",
	"corks",
	"positronics",
	"pancakes",
	"robots",
	"curries",
	"biscuits",
	"tuning forks",
	"glass bottles",
	"razor blades",
	"whisky",
	"ale",
	"philosophical theories",
	"mathematical formulae",
	"works of fiction",
	"fireworks and pyrotechnics",
	"ink",
	"beadwork",
	"flatware",
	"rocks",
	"dirt",
	"succulent plants",
	"songbirds",
	"boots",
	"spear points",
	"joot",
	"rocket boosters",
	"thrusters",
	"navigation computers",
	"dubious financial instruments",
	"tax shelters",
	"tasty sauces",
	"complex legal documents",
	"intoxicating beverages",
	"wood carvings",
	"engravings",
	"coffee mugs",
	"telephones",
	"carburetors",
	"kettles",
	"corn fritters",
	"conspiracy theories",
	"axioms",
	"random numbers",
	"carbonated sodas",
	"sandwiches",
	"cured meats and cheeses",
	"wood burning computers",
	"bizarre economic theories",
	"airtight religions",
	"lack of humor",
	"spices",
	"onions",
	"towels",
	"zarkons",
	"pajamas",
	"language lessons",
	"cybernetic interpreters",
	"poetry lessons",
	"musical instruction",
	"backrubs",
	"manifestos",
	"religious pamphlets",
	"dubious metaphors",
	"double entendres",
	"jokes",
	"recipes",
	"furniture",
};

static char *Culture[] = {
	"humorous anecdotes",
	"suggestive stories",
	"beverages of unusual size",
	"scalding hot teas",
	"unusual theories of ethics",
	"fractal music",
	"folk tunes",
	"epic poems",
	"humorous doodles", 
	"poetry",
	"choreography",
	"horticulture",
	"art",
	"music",
	"heavy metal",
	"extravagant hairstyles",
	"flamboyant footwear",
	"feasts",
	"high performance gustation",
	"racing ships",
	"ceremonies",
	"parties",
	"festivals",
	"carnivals",
	"fairs",
	"shindigs",
	"concerts",
	"television dramas",
	"horoscopes",
	"predictions",
	"prognostications",
	"nostrums",
	"beverages",
	"delectables",
	"paintings",
	"tapestries",
	"sculptures",
	"wines",
	"racy novellas",
	"computer programming languages",
	"nightclubs",
	"night life",
	"soups",
	"spiritual hogwash",
	"solid engineering",
	"fine workmanship",
};

static char *Traveling_Accessory[] = {
	"pair of sunglasses",
	"bottle of sun screen",
	"sense of humor",
	"patience",
	"stash of bribe money",
	"towel",
	"container of bug spray",
	"bathing suit",
	"pair of hiking shoes",
	"camera",
	"good blaster",
	"phaser rifle",
	"space suit",
	"supply of food",
	"supply of water",
	"vial of salt tablets",
	"vial of antibiotics",
	"big pile of money",
	"big wads of cash",
	"cybernetic translator",
	"set of earplugs",
	"zoort net",
	"water purifier",
	"dispenser of scag repellent",
	"space marine escort", 
	"cold weather gear",
	"bullshit detector",
	"strong stomach",
	"load of cash",
	"strong line of credit",
	"complete set of vaccination documentation",
	"letter of recommendation",
	"good suit of clothes",
	"flashlight",
	"sense of smell",
	"set of noseplugs",
	"rational state of mind",
	"skeptical bent of mind",
	"way with words",
	"silver tongue",
	"way with a blaster",
	"set of fishing tackle",
	"vial of anti-venom",
	"mind altering substances",
};

static char *Bring_Your[] = {
	"Be sure to bring your",
	"Don't forget your",
	"Don't leave home without your",
	"Bring a",
	"You'll be sorry if you fail to bring your",
	"Travel with a",
	"Don't even think of coming here without your",
	"Consider it mandatory to bring your",
	"A fate worse than death awaits those forget to bring their",
	"Do not bother to bring your",
	"It is forbidden to bring a",
	"Be warned to bring a",
	"You will definitely need a",
	"You can't get by without a",
	"You will not enjoy yourself without your",
	"It is not permitted to bring your",
	"Bring your",
	"Visitors are advised to bring a",
	"Travelers are advised to bring their",
	"It is inadvisable to bring your",
	"The wise traveler will bring a",
	"Word to the wise, bring a",
	"The seasoned traveler knows to bring a",
	"Be advised, bring your",
	"Well worthwhile to bring your",
	"Absolutely do bring your",
	"Under no circumstances forget to bring your",
};

static char *Planet[] = {
	"planet",
	"system",
	"planet",
	"world",
	"planetoid",
	"place",
	"locale",
	"region",
};

static char *Climate[] = {
	"tropical",
	"icy",
	"desert",
	"aqueous",
	"gaseous",
	"mountainous",
	"featureless",
	"stormy",
	"pleasant",
	"warm",
	"cold",
	"frozen",
	"hot",
	"dry",
	"snowy",
	"rainy",
	"temperate",
};
	
static char *Be_advised[] = {
	"warning,",
	"be advised,",
	"let it be known,",
	"you are advised to",
	"attention,",
	"this will be your only warning,",
	"you are warned to",
	"Word to the wise,",
	"you are strongly cautioned to",
	"Be warned,",
};

static char *Cease_fire[] = {
	"cease fire at once",
	"cease fire",
	"cease hostilities",
	"cool your lasers",
	"suspend fire",
	"desist hostilities",
	"chill your lasers",
	"suspend hostilities at once",
	"belay fire",
	"cease firing",
};

static char *You_will_be[] = {
	"you will be",
	"you'll be",
	"your ship will be",
	"you and your crew will be",
	"that garbage scow you call a ship will be",
	"your hull will be",
	"what's left of your ship will be",
	"your tin can of a ship will be",
	"your ship full of corpses will be",
	"your rattling hull will be",
};

static char *Get_lost[] = {
	"get lost",
	"get out of here",
	"leave immediately",
	"make yourself scarce",
	"make like a tree and get outta here",
	"clear the area",
	"remove yourself at once",
	"vacate this space immediately",
	"depart at once",
	"scram",
	"get outta here",
	"bug off",
	"back off",
	"retreat immediately",
	"leave the area at once",
	"withdraw at once",
};

static char *Destroyed[] = {
	"destroyed",
	"incinerated",
	"vaporized",
	"blown out of the sky",
	"blasted out of the sky",
	"blasted to embers",
	"charred to bits",
	"blown to smithereens",
	"fried to a crisp",
	"reduced to smoke",
	"burned to embers",
	"sent to meet Zarkon's ghost",
	"reduced to molten slag",
	"blasted to cinders",
	"a fun bit of target practice",
	"reduced to slag and cinders",
	"blasted to Nebulon seven",
	"scorched to ashes",
	"smoked like a kipper",
	"regrettably incinerated",
	"unseasonably warm for a few microseconds",
	"lit up like a Zarkon wedding party",
	"having your absorption spectrum rather severely tested",
	"eating way too many photons for breakfast",
};

#define ARRAYSIZE(x) (sizeof(x) / sizeof((x)[0]))

static char *random_word(struct mtwist_state *mt, char *w[], int nwords)
{
	int x;

	x = (int) (((double) mtwist_next(mt) / (double) (0xffffffff)) * nwords);
	return w[x];
}

static char *you(struct mtwist_state *mt)
{
	return random_word(mt, You, ARRAYSIZE(You));
}

static char *action(struct mtwist_state *mt)
{
	return random_word(mt, Action, ARRAYSIZE(Action));
}

static char *like(struct mtwist_state *mt)
{
	return random_word(mt, Like, ARRAYSIZE(Like));
}

static char *adjective(struct mtwist_state *mt)
{
	return random_word(mt, Adjective, ARRAYSIZE(Adjective));
}

static char *beast(struct mtwist_state *mt)
{
	return random_word(mt, Beast, ARRAYSIZE(Beast));
}

static char *nationality(struct mtwist_state *mt)
{
	return random_word(mt, Nationality, ARRAYSIZE(Nationality));
}

static char *qnationality(struct mtwist_state *mt)
{
	int x;
	x = (int) (((double) mtwist_next(mt) / (double) (0xffffffff)) * 1000);
	if (x < 100)
		return nationality(mt);
	else
		return nothing;
}

static char *are(struct mtwist_state *m)
{
	return random_word(m, Are, ARRAYSIZE(Are));
}

static char *bad_thing(struct mtwist_state *mt)
{
	return random_word(mt, Bad_thing, ARRAYSIZE(Bad_thing));
}

void infinite_taunt0(struct mtwist_state *mt, char *buffer, int buflen)
{
	snprintf(buffer, buflen, "%s %s %s %s %s",
			you(mt), action(mt), like(mt), adjective(mt), beast(mt));
}

void infinite_taunt1(struct mtwist_state *mt, char *buffer, int buflen)
{
	snprintf(buffer, buflen, "%s %s %s %s %s %s",
			you(mt), action(mt), like(mt), adjective(mt), nationality(mt), beast(mt));
}

void infinite_taunt2(struct mtwist_state *mt, char *buffer, int buflen)
{
	snprintf(buffer, buflen, "%s %s %s %s",
			you(mt), are(mt), adjective(mt), bad_thing(mt));
}

void infinite_taunt3(struct mtwist_state *mt, char *buffer, int buflen)
{
	snprintf(buffer, buflen, "%s %s %s %s %s",
			you(mt), are(mt), adjective(mt), nationality(mt), bad_thing(mt));
}

void infinite_taunt(struct mtwist_state *mt, char *buffer, int buflen)
{
	switch (mtwist_next(mt) % 4) {
	case 0:
		infinite_taunt0(mt, buffer, buflen);
		break;
	case 1:
		infinite_taunt1(mt, buffer, buflen);
		break;
	case 2:
		infinite_taunt2(mt, buffer, buflen);
		break;
	case 3:
		infinite_taunt3(mt, buffer, buflen);
		break;
	default:
		infinite_taunt1(mt, buffer, buflen);
		break;
	}
}

static char *known_for(struct mtwist_state *mt)
{
	return random_word(mt, Known_For, ARRAYSIZE(Known_For));
}

static char *exceptional(struct mtwist_state *mt)
{
	return random_word(mt, Exceptional, ARRAYSIZE(Exceptional));
}

static char *terrible(struct mtwist_state *mt)
{
	return random_word(mt, Terrible, ARRAYSIZE(Terrible));
}

static char *avoid(struct mtwist_state *mt)
{
	return random_word(mt, Avoid, ARRAYSIZE(Avoid));
}

static char *producing(struct mtwist_state *mt)
{
	return random_word(mt, Producing, ARRAYSIZE(Producing));
}

static char *product(struct mtwist_state *mt)
{
	return random_word(mt, Product, ARRAYSIZE(Product));
}

static char *culture(struct mtwist_state *mt)
{
	return random_word(mt, Culture, ARRAYSIZE(Culture));
}

static char *planet(struct mtwist_state *mt)
{
	return random_word(mt, Planet, ARRAYSIZE(Planet));
}

static char *climate(struct mtwist_state *mt)
{
	return random_word(mt, Climate, ARRAYSIZE(Climate));
}

static char *bring_your(struct mtwist_state *mt)
{
	return random_word(mt, Bring_Your, ARRAYSIZE(Bring_Your));
}

static char *traveling_accessory(struct mtwist_state *mt)
{
	return random_word(mt, Traveling_Accessory,
				ARRAYSIZE(Traveling_Accessory));
}

static void break_lines(char *buffer, int line_len)
{
	int i, so_far, len;

	if (!line_len)
		return;
	len = strlen(buffer);
	so_far = 0;
	for (i = 0; i < len; i++) {
		if (buffer[i] == ' ' && so_far > line_len) {
			buffer[i] = '\n';
			so_far = -1;
		}
		so_far++;
	}
}

static char *be_advised(struct mtwist_state *mt)
{
	return random_word(mt, Be_advised, ARRAYSIZE(Be_advised));
}

static char *cease_fire(struct mtwist_state *mt)
{
	return random_word(mt, Cease_fire, ARRAYSIZE(Cease_fire));
}

static char *get_lost(struct mtwist_state *mt)
{
	return random_word(mt, Get_lost, ARRAYSIZE(Get_lost));
}

static char *you_will_be(struct mtwist_state *mt)
{
	return random_word(mt, You_will_be, ARRAYSIZE(You_will_be));
}

static char *destroyed(struct mtwist_state *mt)
{
	return random_word(mt, Destroyed, ARRAYSIZE(Destroyed));
}

void planet_description(struct mtwist_state *mt, char *buffer, int buflen, int line_len)
{
	char do_avoid[100];

	strcpy(do_avoid, avoid(mt));
	do_avoid[0] = toupper(do_avoid[0]);

	snprintf(buffer, buflen, "This %s %s %s %s %s %s %s and %s %s %s %s. %s the %s %s.  %s %s.\n",
		climate(mt), planet(mt), known_for(mt), producing(mt),
			exceptional(mt), qnationality(mt), product(mt),
			known_for(mt), exceptional(mt), qnationality(mt),
			culture(mt),
			do_avoid, terrible(mt), product(mt),
			bring_your(mt), traveling_accessory(mt));
	break_lines(buffer, line_len);
}

void starbase_attack_warning(struct mtwist_state *mt, char *buffer,
			int buflen, int line_len)
{
	char do_avoid[100];

	strcpy(do_avoid, avoid(mt));
	do_avoid[0] = toupper(do_avoid[0]);

	snprintf(buffer, buflen, "%s %s and %s or %s %s\n",
		be_advised(mt), cease_fire(mt), get_lost(mt), you_will_be(mt),
		destroyed(mt));
	break_lines(buffer, line_len);
}

void cop_attack_warning(struct mtwist_state *mt, char *buffer,
			int buflen, int line_len)
{
	snprintf(buffer, buflen, "You are in violation of spacefaring ordinance 773-za"
			" and %s %s" , you_will_be(mt), destroyed(mt));
	break_lines(buffer, line_len);
}


#ifdef TEST_TAUNT
#include "mtwist.h"
#include <sys/time.h>
static void set_random_seed(struct mtwist_state **mt)
{
	struct timeval tv;

	gettimeofday(&tv, NULL);
	*mt = mtwist_init(tv.tv_usec);
}

int main(int argc, char *argv[])
{
	int i;
	char buffer[1000];
	struct mtwist_state *mt;

	set_random_seed(&mt);

	for (i = 0; i < 1000; i++) {
		/* infinite_taunt(buffer, sizeof(buffer) - 1); */
		/* planet_description(mt, buffer, sizeof(buffer) - 1, 60); */
		cop_attack_warning(mt, buffer, sizeof(buffer) - 1, 50);
		printf("%s\n", buffer);
	}
	free(mt);
	return 0;
}
#endif
