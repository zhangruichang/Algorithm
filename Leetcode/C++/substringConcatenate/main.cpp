/*
Author: richard
Contact: zhangruichang112@gmail.com
*/
#include<set>
#include<map>
#include<list>
#include<cmath>
#include<queue>
#include<stack>
#include<ctime>
#include<cstdio>
#include<string>
#include<vector>
#include<climits>
#include<cstdlib>
#include<cstring>
#include<fstream>
#include<sstream>
#include<iostream>
#include<algorithm>
#include <unordered_set>
#include <unordered_map>
using namespace std;
const int maxn = 1e6 + 10;
typedef long long LL;
typedef unsigned long long ULL;
//int, -2^31~2^31-1    -2.1*10^9~2.1*10^9 (-2147483648-2147483647)
//unsigned int, 0~2^32-1  0~4.2*10^9
//long long  -2^63~2^63-1 -9*10^18~9*10^18
//unsigned long long 0~2^64-1  0~1.8*10^19
typedef pair<int, int> pii;
typedef vector<int> vi;
#define fi first
#define se second
#define iOS  ios_base::sync_with_stdio(false)
int getint(){
	int t = 0, flag = 1; char c = getchar();
	while (c<'0' || c>'9' || c == '-')
	{
		if (c == '-')
			flag = -1;
		c = getchar();
	}
	while (c >= '0'&&c <= '9')
		t = t * 10 + c - '0', c = getchar();
	return t*flag;
}
int GCD(int m, int n)
{
    return !m ? n : GCD(n%m, m);
}
template <typename T>
string to_string(T value)
{
  //create an output string stream
  ostringstream os ;

  //throw the value into the string stream
  os << value ;

  //convert the string stream into a string and return
  return os.str() ;
}
LL MultMod(LL a,LL b,LL MOD)
{
    a %= MOD;
    b %= MOD;
    LL ret = 0;
    while(b){
        if (b & 1){
            ret += a;
            if(ret >= MOD) ret -= MOD;
        }
        a = a << 1;
        if (a >= MOD) a -= MOD;
        b = b >> 1;
    }
    return ret;
}
int a[maxn], n, t, m;

class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        if(s=="" || words.size()==0) return {};
        unordered_map<string, int> um;
        vector<int> ans;
        for(auto e: words){
            um[e]++;
        }
        int len=words[0].size();
        for(int i=0;i+words.size()*len<=s.size();i++){//end index for optimize
            unordered_map<string, int> cur(um);
            bool ok=1;
            for(int j=0;j<words.size();j++){
                if(i+(j+1)*len>s.size()) {ok=0;break;}
                string curs=s.substr(i+j*len, len);
                if(!cur.count(curs) || !cur[curs]) {ok=0;break;}
                cur[curs]--;
            }
            if(ok) ans.push_back(i);
        }
        return ans;
    }
};

int main()
{
/*
#ifndef ONLINE_JUDGE
    freopen ("in.txt" , "r" , stdin);
    freopen ("out.txt" , "w" , stdout);
#endif
*/
  string s="cxksvbkmmlkwviteqccjhsedjmoyimskmeehhovubiszsodiqhtyaxdlktmuiggukldubzqdjiebyjkpqfpqdsepmqluwrqictcguslddphdyrsowjhbcnsqddmbvclzvqhsksxnhethvnyuxfxzsqpxvdasflscbzumssbbwuluijqhqngkfxhdahvhunjwpgkjylmwixssgizyyhifepigyenttyriebtcogbwftqmcpmcwvhcmsklyxgryxccyvhodiljbbxftjhrerurleejekacheehclvfviqxmnefzowdhswsxcbdmdfvilekzcrukityxyfwmcctwanvdoyptfnbtrnsthoepieoiklwmppkpegssgknmxpfoezilnocxsrfcebqtsdkwjfqppedmvkczjmnzcpwxiebofujyxuwgzpxotdcqnerzteyvwwseauvgoeglyctzrspmvrcjyuiraimwehdfbalretcfxxeppwdnniwnegeeotdsaixdikuodytbxasmwxzlfxzldfstaxmcflfpybdbzzewzylxwmidkjrprjjtgxwnideifjkeiqdjpogncrsmcjetsnnamlpwotftdranhdxytfnvwgkzroukdjmpucnjxscajcqtfptaujwtrguiwouzyhqulddiygjjkbesqyskjofawzisqdrqkjkvnodlwowgrbyhzruihzkezsyrvshhbreqhkbfaymsbmzaftkpvutwotnklutnnydxihcihqcidckkxwzssuogodszzmopmumwbogkhjukleukcufuqvcezxgylunxobvrsbbzkvlxbhiddnzuieyhbeimbxlpzghthksugdrjkznoomkzsiitpqhqquhraqkkbcgjhxstzhjpwtoocxirprjfmqwmhgyikgtrellftwupqldsinlzfwfrmdfvmgfwmyqsmdxhzuwpfbjprwowsvphzuelckjrkbjwejdgdbxkdhzwfnsaljjkdnxixizikigqrmwwnugsdhokxikirtuxjtfibgslozeilagywptbwhmvqwdjszgbsnjutchkdluooaompjooraljypusobvjohdklmuqyogoquaigqwxsjiryclpfjywsdgdpctpqzdivgqbwoapykiypvpuepswsybkcwzsxfbvntylibcglmeciuzojrnesqounppmwshjlgxtjzzumgzwcymlpbrjsfehxtttldfwlcsudrqpzpnbnapfbgovoucnnygadnzqrrkvkckkuanjaeodnfzbzdqpdypgmoydhiysnlehnrsnwjsloropxeeacwjomhuusuohhsqulihjrcuhvixsmdvpbefqnbmhwaodueafnjpellmhulbiqwzscfiqiuxgwomqsmxfvmmhyaqunrcdocvqjfirbiyzwmpoypwtdkcdksxzkacaeasnhbgjlgkhsaxqrvmufoyrjxqvztxdvpscszndfymaamqrhelnvleejxbiqyonpgpihdnpbcpbohuvmfkhtrncoqmgqatfjkpqnffqjutxenuqvhzoyosogeuwhpdqzvipaofjkbiooeejlfzjvrzbytxhidxkyfzavglghtuyzbhlgjwcawdardhcigmgonijvtpdokdnlmatvzxyvdymggqqmcyargmnbbqpnveahhudgtbdwzrehiuwmsyeykrbojqbexelgaomtrrqtiucspyfhxjijajxjcbpbfahfrvyimodwjgpyewhdfrphbmsfnhguhpzakalyoowzunzbjhgqyvxbkrgzyouidtinttnkkkjezjhjsqbslzuvqcvrrrzwkjkgdzsnldtlmdwgtxzewvcpxzgqqhncqzkvackmgexujtbcqcipxmgwlopdvcgndqjdvtpbzoxijamacvrzjxyvnnykpgxuxixucpvddumpvapxxizhhxeukcebjdvimucqjztpvheqivqfdpokosgyxkbipwsbqurcvltquzjcwzkzqyletteqffaubswtonxjasbvrkznljodkbhfunvzsxwvpsrdhqokjpfcceqnqgrckaheoegibceqwvvdljnwyuzcbrsrxlthlcobgwkhyqzwlubyfrvflwimnafknauacickeoteeucrodrvuobikjwxlckyeeyjoctusnawhcpyfhtcvukifgfskpspvrylvtfogfmqhcqpjlrgidopjwiunalltjwpccflhrdrvtgegznocdgnzohposakdwbgagtkxwbtrjzxkoomuuzvkjkadkkhjlpjtittewoxfpwpemdygftsqgttqfcbtrlmbefhbteijbapnfpwkkqcslwjramkuxyveeffzlpkopbevsahdskveigvivhesfcwlhdnstxhkblhtnpyfbwljegrzpysxaqihwxzrxibyvjriasqbobmskfsbdmydejkagmrdutdqevagpsjduvxgarhefihkrukzgcdcxguddvlsnuxjrxrrozvuhfgazqzhuejtlgyqdllsfiewhvqwunsdsydtqfanjmiwujpxuapcktysrqoleirwiwsabupngajcjyzdarflmgddwtradizletninfvwfgyohathrbsdhxjfsaivkjiqcyypdvniemylmrufspkbmthhvpcfanwclwtouhwavunjnhogwyhluqsphwxhjvjutfkpoipjecusmiaiijvcapujmrrxocshhexxnmgrraldklntxlxzarimkzkyceglkfjxtrrkucpeqfznqxmqqufbwrbaxhnhoyfiqwumakqsrsfhrtzhqekoxmouvdckchsufmghyyarqhyhbartebhenxylaavcjnwobeycdytthudiuudavkeljdwkdtopindjrdnudjqlftvznzbklgxvlthqmvfuklgcovysgodlhakwzmjnugifcpvqmbnzovdcqbwzsbkbcvydjhqdpakrphkeixdwuibmjxlbzwddtdgcmxhbxtvpafvleajyikkrkyvluaondwrptastvnivufiafsanengqldbfdrugonxjnqckfkfcrocwiflosufdxikbaejqthzgzcqeoxggnlexqqmkktpjbzkbfwtydtgcvyilxrrlewkwowgapvjruwubsozxjhzgfjrcalpejaazyizodihzedaytbveiwkpgesgphnajpziyyybihdpkfnghlkrhvhnzbwqkjquareyrcczjfqvkebtpmnyjwmkxkajvsfvljucnwbybsunyxjplwnusbgrlicgaieltynjwrhzlbmlzvamtphntngeyjnytrmorbxnufmfiasjwswrkdfdsljqwwrppfgggdtdkhktidcgxyxhdcmyqwqosjekomqxpmaatkvbpxhnyhwdljdbfuszfwjukctzovbjhwnxwwkwdgzppdswzkweihasjtuzoxjywwvsuhoynppfujdvwzaghcbsyxsoubmqzhitoyteqklmwoisqkaxmbpkyhztklllvwhjuapmnazjrhbhrbgffvqdfryrckdzgkjcmapzdqiuzldspjxugpxlgydliikouvsgyjgbzqxacasrjslphkdqiidsqniklbsjkymmpjmtlfkuxxlghowsyzkopvaawtlitzukijdtqppnoavyrsqptcgixgkvbxgxwcjglpzbeqqvrmtigjzbnfknowkrwqostybgnaktraokohuwstyibkvpihgeyxztvabkcldvosfcbbbuxzcajzptgxygwzbrzddbohzcbgheiiyhhchsdylmvlsukuljxrnnymqbsxfchgjoksiqqtcohwirqvdpmsfmevpyuxbbdmrpfzfvujldgtvypaqdsvqwsfwoczrhmiztjgqfqcjyvewmeoqwjiudnqrssizesazdhpjxrsxpytdektctbwzroslgbmmvnlzubitucqjalnevigrmeqfuiqblcnhrbilcqgyuwiukxafhgwtmoagxqhkvxtmabaetgcnfkjpjjurrtmdhnkgfttasmpuqpyjxbzcnirxsoojjcpspbbvuuxpimjydikbjjdwrxvlnlvwokqflrchlaywokussetdnybhxzsmkpkybbgosiwgiwcxgwradmfsmhzkguwsjhtlizbchziswmrcjifowkgitisbcrunanakocmxbxpxjicushiotpxnxrobikoixpunrhlsgcsrlwmdfusylplkgclrmcbkrwzkfkelnyeyuqdznvyamllvnymacnmvllfqymdlkilfaognmgqysbvfbjhextbkhhdftgsfqdmrttgfbwgtzdbdnijmekwntzsoikuypiridaqfyyaybbdommasyxfsyxggjchylyiqayvzywxazcolordookgmhpvstcqgcbxdzseaqbaqfqdvhjjvtqkbhhtajmhnneqoyuopxqhehkzotjmnbyqiflkoztdmzwdaqtpqkyuriwhefvtgtjqywcowyskxonxghoytovmxrtdypwgihyjdazzytkyjzxqioqbcnnbgheeyakihitnltmlmyjwyjogxeizuxbaghfeirprcienbtyqrkmrvaasgktchwdoekuobjffsmsvftlyfxqazquiankjkpxozucddjixxdtcweddevffnznpoayypyopssuxecxbfqgdwjgaglgtmvibvibngseakyaqaxuipalllsorfwksrutpcuelminzgnriklqzlcnwwbpbxzvqvohylllztyaboskadccrgppcsfgrgbhcsrcfcngynhbbbncgqexyvpbnujeamneeegljtsjhbkkcamissiqnxrarcetpsyvyehhabqjcbtgdiovawlqtfqmhxgwrgupmdxoepxistovdeqfdcvyhmloltnczhrnkqcqgzayuquxumfzoayxolozeddfkxswnuovwowqeqqaevctxasmlgnpjrwvootdjhzhxvzdnpgrmimmifavnnkxgiuwwoahxbovwqalhgcworiwyitlxdkenfakvatsbkpzaqkhwpdnillgvfrtkexyjzigcdydnqfpgrxegcroqduliogssfqdfalhglmtbrjjjiormhgckcqsswnmcfrhgcqoochrusbfcrwpyerjjhdbgsqiyhrgmhucjdtfwwmanjpopjxasceyvugvdzbpgvtsapxwlkzbvopmxonqsrqplxkqwlgfibxjquheggfdxwqwmfoewfujegzcuhhclenbbxfjfmncifbumpbiuxtadudxekcprrquqyfwksatzbpltsvnpqovltspdwgwqysgwyehsfcsitfbmdrdthygatxfrdchcuoysshlzlfifmltpcyljxrlsprjuttwpjxkbexdsenzqysidqtopmajbrvwmoudxrpaymdqsspjtjtwbomtameefzctpwxoqmpobugtnxeiizelnqeofjskkugasdoirfyucgqpfuznudzjvfxaqrnbntdiyrqrzrmbxcsdyrsuwterzdurxjskcvscpltqchrbjlgkczgyumrtqlnnufzyduauhwklddmpotbsuhsoulkmxxbtcauhwwbdsnqysdniyoasvugrgqdfneashubftdjnsblneyvcoyumsddatjhjnidueeaxjllemyrtxmxnkszfxfhqopbbxeydladunoybopwlcubooavlfddvsfxrlxuwzxrmnrpchmpliqbwtxhyckuuptldshzrfsfukwwtiogqehoxgvyigucxppahzcygwfaibzbmnjetrttzoriwnmucewldaljxqjfrkjdxsitldmlrfvoshkwnghqhszgilnbvwhvrroeuaplhmbzulxhueabybjimwjkvqhmjvqdxireuufqgcaaiadgbmoqkzafshtbemhduahquohasjcajfimryccxejpndtrpcwlcdbwtkzltbnchxpavtevyqmltffkjbvlhwkajjocmdhvbywyrctpsidnpixzlsksrwvaflcuojprhlqbqlqivtwldtkpowjftefaphugtkxcxpdndwyyrujvpvmdsxklcpntzibusbwpqcdvybupxfmobautyegcwtxvbzpvanlspqoptkhspviswclwjtafnxcqytmaiztarjpmtygkuodstqockqjznnpmgdmqehqxqgjlgrwagbuzrkdbaocobscjxqzeyqbqynegechmddnuosyogaejuiuuzuyzmzrmovutxbfchvzvnzjuzqfwyaqxwqykrqygnsznwgpddoyrnjnpzsnysdxqvyamqysdttqpcgsfwswkbjzdemdyrcpoaraqstulomcquuwroudrgcumqzkjcbxctzvlsryhdazawxrksubayy";
  vector<string> words={"otftdranhdxytfnvwgkzroukdj","iflkoztdmzwdaqtpqkyuriwhef","lbsjkymmpjmtlfkuxxlghowsyz","cddjixxdtcweddevffnznpoayy","snjutchkdluooaompjooraljyp","fuszfwjukctzovbjhwnxwwkwdg","frmdfvmgfwmyqsmdxhzuwpfbjp","ukityxyfwmcctwanvdoyptfnbt","mhnneqoyuopxqhehkzotjmnbyq","vtgtjqywcowyskxonxghoytovm","wouzyhqulddiygjjkbesqyskjo","mfiasjwswrkdfdsljqwwrppfgg","zruihzkezsyrvshhbreqhkbfay","rsxpytdektctbwzroslgbmmvnl","jdwrxvlnlvwokqflrchlaywoku","xhnhoyfiqwumakqsrsfhrtzhqe","gtbdwzrehiuwmsyeykrbojqbex","tpcyljxrlsprjuttwpjxkbexds","tsjhbkkcamissiqnxrarcetpsy","keiqdjpogncrsmcjetsnnamlpw","rquqyfwksatzbpltsvnpqovlts","tdgcmxhbxtvpafvleajyikkrky","qvrmtigjzbnfknowkrwqostybg","vluaondwrptastvnivufiafsan","rnsthoepieoiklwmppkpegssgk","cyypdvniemylmrufspkbmthhvp","ihcihqcidckkxwzssuogodszzm","chrusbfcrwpyerjjhdbgsqiyhr","wmeoqwjiudnqrssizesazdhpjx","ommasyxfsyxggjchylyiqayvzy","kwntzsoikuypiridaqfyyaybbd","cwjomhuusuohhsqulihjrcuhvi","wxazcolordookgmhpvstcqgcbx","nusbgrlicgaieltynjwrhzlbml","xrtdypwgihyjdazzytkyjzxqio","xfvmmhyaqunrcdocvqjfirbiyz","fuklgcovysgodlhakwzmjnugif","hzhxvzdnpgrmimmifavnnkxgiu","xsmdvpbefqnbmhwaodueafnjpe","xfbvntylibcglmeciuzojrnesq","cnhrbilcqgyuwiukxafhgwtmoa","xkajvsfvljucnwbybsunyxjplw","zuieyhbeimbxlpzghthksugdrj","gbzqxacasrjslphkdqiidsqnik","jxtrrkucpeqfznqxmqqufbwrba","chziswmrcjifowkgitisbcruna","jyzdarflmgddwtradizletninf","pcktysrqoleirwiwsabupngajc","dkenfakvatsbkpzaqkhwpdnill","kbiooeejlfzjvrzbytxhidxkyf","wlopdvcgndqjdvtpbzoxijamac","xsoojjcpspbbvuuxpimjydikbj","faubswtonxjasbvrkznljodkbh","uqsphwxhjvjutfkpoipjecusmi","nawhcpyfhtcvukifgfskpspvry","xkdhzwfnsaljjkdnxixizikigq","zxgylunxobvrsbbzkvlxbhiddn","alltjwpccflhrdrvtgegznocdg","gffvqdfryrckdzgkjcmapzdqiu","hzedaytbveiwkpgesgphnajpzi","wmpoypwtdkcdksxzkacaeasnhb","hsdylmvlsukuljxrnnymqbsxfc","bbbncgqexyvpbnujeamneeeglj","bjhgqyvxbkrgzyouidtinttnkk","pyuxbbdmrpfzfvujldgtvypaqd","cfanwclwtouhwavunjnhogwyhl","plkgclrmcbkrwzkfkelnyeyuqd","ugvdzbpgvtsapxwlkzbvopmxon","msbmzaftkpvutwotnklutnnydx","pdwgwqysgwyehsfcsitfbmdrdt","elgaomtrrqtiucspyfhxjijajx","biqyonpgpihdnpbcpbohuvmfkh","llmhulbiqwzscfiqiuxgwomqsm","mpucnjxscajcqtfptaujwtrgui","gdzsnldtlmdwgtxzewvcpxzgqq","gdtdkhktidcgxyxhdcmyqwqosj","zubitucqjalnevigrmeqfuiqbl","aymdqsspjtjtwbomtameefzctp","kjezjhjsqbslzuvqcvrrrzwkjk","zavglghtuyzbhlgjwcawdardhc","fawzisqdrqkjkvnodlwowgrbyh","vrzjxyvnnykpgxuxixucpvddum","rdutdqevagpsjduvxgarhefihk","ydhiysnlehnrsnwjsloropxeea","hgjoksiqqtcohwirqvdpmsfmev","jyxuwgzpxotdcqnerzteyvwwse","sozxjhzgfjrcalpejaazyizodi","usobvjohdklmuqyogoquaigqwx","tmdhnkgfttasmpuqpyjxbzcnir","quareyrcczjfqvkebtpmnyjwmk","rmwwnugsdhokxikirtuxjtfibg","qsrqplxkqwlgfibxjquheggfdx","rukzgcdcxguddvlsnuxjrxrroz","oomuuzvkjkadkkhjlpjtittewo","wqwmfoewfujegzcuhhclenbbxf","yjogxeizuxbaghfeirprcienbt","qbwoapykiypvpuepswsybkcwzs","lvtfogfmqhcqpjlrgidopjwiun","rwowsvphzuelckjrkbjwejdgdb","jfqppedmvkczjmnzcpwxiebofu","hygatxfrdchcuoysshlzlfifml","gxqhkvxtmabaetgcnfkjpjjurr","zppdswzkweihasjtuzoxjywwvs","hgyikgtrellftwupqldsinlzfw","kckkuanjaeodnfzbzdqpdypgmo","aiijvcapujmrrxocshhexxnmgr","sjiryclpfjywsdgdpctpqzdivg","kuxyveeffzlpkopbevsahdskve","uqvhzoyosogeuwhpdqzvipaofj","gjhxstzhjpwtoocxirprjfmqwm","cwiflosufdxikbaejqthzgzcqe","qeqqaevctxasmlgnpjrwvootdj","ymggqqmcyargmnbbqpnveahhud","ekomqxpmaatkvbpxhnyhwdljdb","zvamtphntngeyjnytrmorbxnuf","uhoynppfujdvwzaghcbsyxsoub","efhbteijbapnfpwkkqcslwjram","koxmouvdckchsufmghyyarqhyh","tthudiuudavkeljdwkdtopindj","nwwbpbxzvqvohylllztyaboska","dccrgppcsfgrgbhcsrcfcngynh","qdpakrphkeixdwuibmjxlbzwdd","ftgsfqdmrttgfbwgtzdbdnijme","ounppmwshjlgxtjzzumgzwcyml","cpvqmbnzovdcqbwzsbkbcvydjh","pbrjsfehxtttldfwlcsudrqpzp","qbcnnbgheeyakihitnltmlmyjw","ztvabkcldvosfcbbbuxzcajzpt","xfpwpemdygftsqgttqfcbtrlmb","hncqzkvackmgexujtbcqcipxmg","ilfaognmgqysbvfbjhextbkhhd","hvqwunsdsydtqfanjmiwujpxua","yqrkmrvaasgktchwdoekuobjff","egeeotdsaixdikuodytbxasmwx","jfmncifbumpbiuxtadudxekcpr","slozeilagywptbwhmvqwdjszgb","kkugasdoirfyucgqpfuznudzjv","pvapxxizhhxeukcebjdvimucqj","bqurcvltquzjcwzkzqyletteqf","cbrsrxlthlcobgwkhyqzwlubyf","mqzhitoyteqklmwoisqkaxmbpk","nbnapfbgovoucnnygadnzqrrkv","ztpvheqivqfdpokosgyxkbipws","auvgoeglyctzrspmvrcjyuirai","yhmloltnczhrnkqcqgzayuquxu","funvzsxwvpsrdhqokjpfcceqnq","vuhfgazqzhuejtlgyqdllsfiew","gmhucjdtfwwmanjpopjxasceyv","vpscszndfymaamqrhelnvleejx","dzseaqbaqfqdvhjjvtqkbhhtaj","zylxwmidkjrprjjtgxwnideifj","nzohposakdwbgagtkxwbtrjzxk","igvivhesfcwlhdnstxhkblhtnp","trncoqmgqatfjkpqnffqjutxen","vwfgyohathrbsdhxjfsaivkjiq","rdnudjqlftvznzbklgxvlthqmv","kopvaawtlitzukijdtqppnoavy","raldklntxlxzarimkzkyceglkf","nakocmxbxpxjicushiotpxnxro","wxoqmpobugtnxeiizelnqeofjs","smsvftlyfxqazquiankjkpxozu","fwksrutpcuelminzgnriklqzlc","nefzowdhswsxcbdmdfvilekzcr","ibvibngseakyaqaxuipalllsor","znvyamllvnymacnmvllfqymdlk","gcvyilxrrlewkwowgapvjruwub","mwehdfbalretcfxxeppwdnniwn","wwoahxbovwqalhgcworiwyitlx","nmxpfoezilnocxsrfcebqtsdkw","engqldbfdrugonxjnqckfkfcro","grckaheoegibceqwvvdljnwyuz","jcbpbfahfrvyimodwjgpyewhdf","rvflwimnafknauacickeoteeuc","gxygwzbrzddbohzcbgheiiyhhc","wcxgwradmfsmhzkguwsjhtlizb","bikoixpunrhlsgcsrlwmdfusyl","ssetdnybhxzsmkpkybbgosiwgi","vyehhabqjcbtgdiovawlqtfqmh","opmumwbogkhjukleukcufuqvce","vjriasqbobmskfsbdmydejkagm","gjlgkhsaxqrvmufoyrjxqvztxd","yyybihdpkfnghlkrhvhnzbwqkj","kznoomkzsiitpqhqquhraqkkbc","yhztklllvwhjuapmnazjrhbhrb","jjiormhgckcqsswnmcfrhgcqoo","rphbmsfnhguhpzakalyoowzunz","igmgonijvtpdokdnlmatvzxyvd","rsqptcgixgkvbxgxwcjglpzbeq","zldspjxugpxlgydliikouvsgyj","enzqysidqtopmajbrvwmoudxrp","naktraokohuwstyibkvpihgeyx","zlfxzldfstaxmcflfpybdbzzew","mfzoayxolozeddfkxswnuovwow","rodrvuobikjwxlckyeeyjoctus","yfbwljegrzpysxaqihwxzrxiby","croqduliogssfqdfalhglmtbrj","gvfrtkexyjzigcdydnqfpgrxeg","xgwrgupmdxoepxistovdeqfdcv","oxggnlexqqmkktpjbzkbfwtydt","pyopssuxecxbfqgdwjgaglgtmv","svqwsfwoczrhmiztjgqfqcjyve","bartebhenxylaavcjnwobeycdy"};
  vector<int> ans=S.findSubstring(s, words);
  for(auto e: ans) cout<<e<<endl;
	return 0;
}
