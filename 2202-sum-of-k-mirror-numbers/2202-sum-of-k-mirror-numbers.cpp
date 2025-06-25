class Solution {
public:
    long long powerArr[11];
    int base;
    queue<string> q;

    long long power(int exponent)
    {
        if (exponent >= 11) return pow(base, exponent);
        if (powerArr[exponent] != 0) return powerArr[exponent];
        return pow(base, exponent);
    }
    long long toDecimal(string s, int base)
    {
        long long num = 0;
        for(int i = s.length()-1, j=0; i >= 0; i--, j++)
        {
            if (s[i] == 0) continue;
            num += (s[i] - '0') * power(j);
        }
        return num;
    }

    bool isMirror(long long num)
    {
        string s = to_string(num);
        for(int i = 0; i < s.length(); i++)
        {
            if (s[i] != s[s.length()-1-i]) return false;
        }
        return true;
    }

    long long bfs(int n)
    {
        int currCount = 0;
        int len;
        int midIdx;
        char mid;
        long long sum = 0;
        long long num;
        string nxt;
        while(!q.empty() && currCount < n)
        {
            string curr = q.front();
            q.pop();
            num = toDecimal(curr, base);
            // cout << "curr string: " << curr << endl;
            // cout << "trying num: " << num << endl;
            if (isMirror(num)) 
            {
                currCount++;
                // cout << "count has become: " << currCount << endl;
                sum += num;
                // cout << "sum has become: " << sum << endl;
                // cout << "num is valid\n";
                if (currCount == n) break;
            }
            len = curr.length();
            midIdx = len/2;
            if (len & 1) // odd, replicate middle
            {
                // cp = s;
                curr.insert(midIdx+1, 1, curr[midIdx]);
                // cout << "generating next: " << curr << endl << endl;
                q.push(curr);
            }
            else // even, try all
            {
                for(int i = 0; i < base; i++)
                {
                    nxt = curr;
                    nxt.insert(midIdx, to_string(i));
                    // cout << "curr: " << curr << ", generating next: " << nxt << endl;
                    q.push(nxt);
                }
                // cout << endl;
            }
        }
        return sum;
    }

    long long kMirror(int k, int n) {
        base = k;
        // cout << "k: " << k << ", n: " << n << endl << endl;
        for(int i = 0; i < 11; i++)
        {
            powerArr[i] = pow(k, i);
        }
        if (n < k)
        {
            return (n*(n+1))/2;
        }
        for(int i = 1; i < k; i++)
        {
            q.push(to_string(i));
        }

        return bfs(n);
    }
};