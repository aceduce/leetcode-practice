#include"Solutions.h"
// https://www.youtube.com/watch?v=mPqqXh8XvWY
int p115::numDistinct(string s, string t) {
	int len_s = s.size();
	int len_t = t.size();
	vector<vector<int>> DP(len_t + 1, vector<int>(len_s + 1, 0));
	//init
	// DP i, j loop starts from 1
	// loop order match the analysis
	for (int i = 0; i <= len_s; i++) DP[0][i] = 1;  // keep deleting, just one way to do it
	for (int i = 1; i <= len_t; i++) {
		for (int j = 1; j <= len_s; j++) {
			if (s[j - 1] == t[i - 1]) {
				DP[i][j] = DP[i - 1][j - 1] + DP[i][j - 1];
			}	
			else DP[i][j] = DP[i][j - 1];
		}
	}
	return DP[len_t][len_s];
}



	void p115::test() {
		string s = "xslledayhxhadmctrliaxqpokyezcfhzaskeykchkmhpyjipxtsuljkwkovmvelvwxzwieeuqnjozrfwmzsylcwvsthnxujvrkszqwtglewkycikdaiocglwzukwovsghkhyidevhbgffoqkpabthmqihcfxxzdejletqjoxmwftlxfcxgxgvpperwbqvhxgsbbkmphyomtbjzdjhcrcsggleiczpbfjcgtpycpmrjnckslrwduqlccqmgrdhxolfjafmsrfdghnatexyanldrdpxvvgujsztuffoymrfteholgonuaqndinadtumnuhkboyzaqguwqijwxxszngextfcozpetyownmyneehdwqmtpjloztswmzzdzqhuoxrblppqvyvsqhnhryvqsqogpnlqfulurexdtovqpqkfxxnqykgscxaskmksivoazlducanrqxynxlgvwonalpsyddqmaemcrrwvrjmjjnygyebwtqxehrclwsxzylbqexnxjcgspeynlbmetlkacnnbhmaizbadynajpibepbuacggxrqavfnwpcwxbzxfymhjcslghmajrirqzjqxpgtgisfjreqrqabssobbadmtmdknmakdigjqyqcruujlwmfoagrckdwyiglviyyrekjealvvigiesnvuumxgsveadrxlpwetioxibtdjblowblqvzpbrmhupyrdophjxvhgzclidzybajuxllacyhyphssvhcffxonysahvzhzbttyeeyiefhunbokiqrpqfcoxdxvefugapeevdoakxwzykmhbdytjbhigffkmbqmqxsoaiomgmmgwapzdosorcxxhejvgajyzdmzlcntqbapbpofdjtulstuzdrffafedufqwsknumcxbschdybosxkrabyfdejgyozwillcxpcaiehlelczioskqtptzaczobvyojdlyflilvwqgyrqmjaeepydrcchfyftjighntqzoo";
		string t = "rwmimatmhydhbujebqehjprrwfkoebcxxqfktayaaeheys";
		//cout << numDistinct("rabbbit", "rabbit") << endl;
		cout << numDistinct(s, t) << endl;
	}