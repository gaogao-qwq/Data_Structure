#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    int n = 0, m = 0, cnt = 0;
    cin >> n >> m;
    vector<string> matrix(n);
    for (int i = 0; i < n; ++i) {
        cin >> matrix[i];
    }
    for (int i = 1; i < n - 1; ++i) {
        for (int j = 1; j < m - 1; ++j) {
            if (matrix[i][j] < matrix[i - 1][j] && matrix[i][j] < matrix[i + 1][j] && matrix[i][j] < matrix[i][j - 1] && matrix[i][j] < matrix[i][j + 1]) ++ cnt;
        }
    }
    cout << cnt;
    return 0;
}
// PHQGHUMEAYLNLFDXFIRCVSCXGGBWKFNQDUXWFNFOZVSRTKJPREPGGXRPNRVY
// STMWCYSYYCQPEVIKEFFMZNIMKKASVWSRENZKYCXFXTLSGYPSFADPOOEFXZBC
// OEJUVPVABOYGPOEYLFPBNPLJVRVIPYAMYEHWQNQRQPMXUJJLOOVAOWUXWHMS
// NCBXCOKSFZKVATXDKNLYJYHFIXJSWNKKUFNUXXZRZBMNMGQOOKETLYHNKOAU
// GZQRCDDIUTEIOJWAYYZPVSCMPSAJLFVGUBFAAOVLZYLNTRKDCPWSRTESJWHD
// IZCOBZCNFWLQIJTVDWVXHRCBLDVGYLWGBUSBMBORXTLHCSMPXOHGMGNKEUFD
// XOTOGBGXPEYANFETCUKEPZSHKLJUGGGEKJDQZJENPEVQGXIEPJSRDZJAZUJL
// LCHHBFQMKIMWZOBIWYBXDUUNFSKSRSRTEKMQDCYZJEEUHMSRQCOZIJIPFION
// EEDDPSZRNAVYMMTATBDZQSOEMUVNPPPSUACBAZUXMHECTHLEGRPUNKDMBPPW
// EQTGJOPARMOWZDQYOXYTJBBHAWDYDCPRJBXPHOOHPKWQYUHRQZHNBNFUVQNQ
// QLRZJPXIOGVLIEXDZUZOSRKRUSVOJBRZMWZPOWKJILEFRAAMDIGPNPUUHGXP
// QNJWJMWAXXMNSNHHLQQRZUDLTFZOTCJTNZXUGLSDSMZCNOCKVFAJFRMXOTHO
// WKBJZWUCWLJFRIMPMYHCHZRIWKBARXBGFCBCEYHJUGIXWTBVTREHBBCPXIFB
// XVFBCGKCFQCKCOTZGKUBMJRMBSZTSSHFROEFWSJRXJHGUZYUPZWWEIQURPIX
// IQFLDUUVEOOWQCUDHNEFNJHAIMUCZFSKUIDUBURISWTBRECUYKABFCVKDZEZ
// TOIDUKUHJZEFCZZZBFKQDPQZIKFOBUCDHTHXDJGKJELRLPAXAMCEROSWITDP
// TPCCLIFKELJYTIHRCQAYBNEFXNXVGZEDYYHNGYCDRUDMPHMECKOTRWOSPOFG
// HFOZQVLQFXWWKMFXDYYGMDCASZSGOVSODKJGHCWMBMXRMHUYFYQGAJQKCKLZ
// NAYXQKQOYZWMYUBZAZCPKHKTKYDZIVCUYPURFMBISGEKYRGZVXDHPOAMVAFY
// RARXSVKHTQDIHERSIGBHZJZUJXMMYSPNARAEWKEGJCCVHHRJVBJTSQDJOOTG
// PKNFPFYCGFIEOWQRWWWPZSQMETOGEPSPXNVJIUPALYYNMKMNUVKLHSECDWRA
// CGFMZKGIPDFODKJMJQWIQPUOQHIMVFVUZWYVIJGFULLKJDUHSJAFBTLKMFQR
// MYJFJNHHSSQCTYDTEAMDCJBPRHTNEGYIWXGCJWLGRSMEAEARWTVJSJBAOIOJ
// LWHYPNVRUIHOSWKIFYGTYDHACWYHSGEWZMTGONZLTJHGAUHNIHREQGJFWKJS
// MTPJHAEFQZAAULDRCHJCCDYRFVVRIVUYEEGFIVDRCYGURQDREDAKUBNFGUPR
// OQYLOBCWQXKZMAUSJGMHCMHGDNMPHNQKAMHURKTRFFACLVGRZKKLDACLLTEO
// JOMONXRQYJZGINRNNZWACXXAEDRWUDXZRFUSEWJTBOXVYNFHKSTCENAUMNDD
// XFDMVZCAUTDCCKXAAYDZSXTTOBBGQNGVVPJGOJOGLMKXGBFCPYPCKQCHBDDZ
// WRXBZMQRLXVOBTWHXGINFGFRCCLMZNMJUGWWBSQFCIHUBSJOLLMSQSGHMCPH
// ELSOTFLBGSFNPCUZSRUPCHYNVZHCPQUGRIWNIQXDFJPWPXFBLKPNPEELFJMT