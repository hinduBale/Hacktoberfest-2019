//Link to question:
//    https://www.codechef.com/JUNE19B/problems/SUMAGCD
//My AC Solution:
//    https://www.codechef.com/viewsolution/24766870
//


/*short and int: -32,767 to 32,767
**unsigned short int and unsigned int: 0 to 65,535
**long int: -2,147,483,647 to 2,147,483,647
**unsigned long int: 0 to 4,294,967,295
**long long int: -9,223,372,036,854,775,807 to 9,223,372,036,854,775,807
**unsigned long long int: 0 to 18,446,744,073,709,551,615.*/

#include <bits/stdc++.h>
#define lli long long int
#define pb push_back
#define mp make_pair
#define eb emplace_back
#define pf push_front
#define MOD 1000000007
#define F first
#define S second
#define inf INT_MAX
//#define gcd(x,y) __gcd(x,y)
#define lcm(a,b) (a*(b/gcd(a,b)))
#define bring_back_deepak_mehta ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

using namespace std;

lli gcd(lli a, lli b)
{
	if (b == 0)
		return a;
	return gcd(b, a % b);
}

int main()
{
    bring_back_deepak_mehta
    lli test;
    cin >> test;
    while(test--)
    {
        lli right_gcd[100005] = {0} ;
        lli left_gcd[100005] = {0};
        lli A[100005] = {0};
        lli n, max_gcd = 0;
        cin >> n;
        for(lli i = 0 ; i < n; i++)
            cin >> A[i];
        sort(A, A + n);
        if(A[0] == A[n - 1])
            cout << 2 * A[0] << endl;
        else
        {
            set <lli> s;
            for(lli i = 0 ; i < n; i++)
                s.insert(A[i]);
            lli no_dup[100005];
            lli it = 0;
            set <lli> :: iterator i;
            for(i = s.begin(); i != s.end(); i++)
            {
                no_dup[it] = *i;
                ++it;
            }
            n = s.size();
            left_gcd[0] = no_dup[0];
            right_gcd[0] = no_dup[n-1];
            for(lli i = 1; i < n; i++)
                left_gcd[i] = gcd(no_dup[i], left_gcd[i-1]);
            for(lli i = n - 2; i >= 0; i--)
                right_gcd[(n - 1) - i] = gcd(no_dup[i], right_gcd[(n-1)-i-1]);

            lli final_res = 0;
            for(lli i = 0; i < n; i++)
            {
                if(i == 0)
                {
                    lli res_right = right_gcd[(n-1) - (i+1)];
                    final_res = res_right;
                }
                else if(i == (n-1))
                {
                    lli res_left = left_gcd[i-1];
                    final_res = res_left;
                }
                else
                {
                    lli res_left = left_gcd[i-1];
                    lli res_right = right_gcd[(n-1) - (i+1)];
                    final_res = gcd(res_left, res_right);
                }

                lli ans = final_res + no_dup[i];
                if(ans > max_gcd)
                    max_gcd = ans;
            }
            cout << max_gcd << endl;
        }
    }
    return 0;
}

