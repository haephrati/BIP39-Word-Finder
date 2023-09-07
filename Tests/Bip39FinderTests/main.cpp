#include <cstdio>
#include <cstdlib>
#include "resource.h"

static void Fail(const char* msg)
{
    std::printf("FAIL %s\n", msg);
    std::exit(1);
}

int main()
{
    if (IDD_BIP39FINDER_DIALOG != 102)
        Fail("dialog");
    if (IDR_MAINFRAME != 128)
        Fail("mainframe");
    if (IDC_EDIT_INPUT != 1000)
        Fail("edit");
    if (IDC_LIST_WORDS != 1001)
        Fail("list");
    if (IDC_STATIC_WORDS_FOUND != 1002)
        Fail("static");
    std::printf("OK Bip39FinderTests\n");
    return 0;
}
