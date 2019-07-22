﻿//ds test1
#if 0
#include <stdio.h>

int CIRQ[5];
int RP = 0, WP = 0;

int QUEUE(int d)
{
    // 코드설계
    if (((WP + 1) % 5) == RP) return -1;
    CIRQ[WP++] = d;
    WP %= 5;
    return WP;
}

int DEQUEUE(int* p)
{
    // 코드설계
    if (RP == WP) return -1;
    *p = CIRQ[RP++];
    RP %= 5;
    return RP;
}

/********************************************************************************/
/* 이부분은설계한코드의오류를확인하기위한테스트코드임가급적수정금지   */
/********************************************************************************/

int main(void)
{
    int i;
    int r;
    int d;

    int oper[] = { 1, 1, 1, 1, 1,  0, 0, 0, 0, 0,  1, 1, 1, 0, 0, 1, 1,  0 };
    int que[] = { 1, 3, 5, 7, 9,  1, 3, 5, 7, 0,  2, 4, 6, 2, 4, 8, 10, 6 };
    int res[] = { 1, 2, 3, 4, -1, 1, 2, 3, 4, -1, 0, 1, 2, 0, 1, 3, 4,  2 };

    for (i = 0; i < (sizeof(oper) / sizeof(oper[0])); i++)
    {
        printf("TEST VECTOR [%d]\n", i);

        if (oper[i] == 1)
        {
            r = QUEUE(que[i]);

            if (res[i] != r)
            {
                printf(">>>>Fail: Expected return => %d, YOur return => %d\n", res[i], r);
                return 0;
            }

            else
            {
                if ((r != -1) && (que[i] != CIRQ[(WP == 0) ? (4) : (WP - 1)]))
                {
                    printf(">>>>Fail: Expected QUEUE data => %d, Your QUEUE data => %d\n", que[i], CIRQ[(WP == 0) ? (4) : (WP - 1)]);
                    return 0;
                }

                else
                {
                    if (r != -1) printf("return => %d, queue => %d\n", r, CIRQ[(WP == 0) ? (4) : (WP - 1)]);
                    else printf("return => %d\n", r);
                }
            }
        }

        else
        {
            r = DEQUEUE(&d);

            if (res[i] != r)
            {
                printf(">>>>Fail: Expected return => %d, YOur return => %d\n", res[i], r);        return 0;
            }

            else
            {
                if ((r != -1) && (que[i] != d))
                {
                    printf(">>>>Fail: Expected DEQUEUE data => %d, Your DEQUEUE data => %d\n", que[i], d);
                    return 0;
                }

                else
                {
                    if (r != -1) printf("return => %d, queue => %d\n", r, CIRQ[(WP == 0) ? (4) : (WP - 1)]);
                    else printf("return => %d\n", r);
                }
            }
        }
    }

    return 1;
}
#endif
