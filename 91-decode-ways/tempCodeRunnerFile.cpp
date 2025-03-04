if (tmpI == s.length() - 1 && i > 0)
            {
                if (s[i - 1] == '1' || s[i - 1] == '2')
                    s.erase(i, tmpI - i);
                else
                    s.erase(i, tmpI - i + 1);
            }
            else
                s.erase(i, tmpI - i);