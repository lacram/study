
ll FasterSolve(ll num)
{
  ll ret = 0;
  bool contains_thirteen = false;

  string num_string = to_string(num);

  for (int i = 0; i < num_string.size(); i++)
  {
    for (char cur = '0'; cur < num_string[i]; cur++)
    {
      if (contains_thirteen)
        ret += decimal[num_string.size() - i - 1];
      else
      {
        if (cur == '1')
        {
          if (i + 1 < num_string.size())
          {
            // 다음꺼 3으로 고정하면, 그 다음은 자유
            ret += decimal[num_string.size() - i - 2];

            // 중복 제거
            ret -= contains_thirteen_cnt[num_string.size() - i - 2];
          }
        }
        else if (cur == '3')
        {
          if (i && num_string[i - 1] == '1')
          {
            // 이 숫자와 이전 숫자로 13이 되는 경우, 다음은 자유
            ret += decimal[num_string.size() - i - 1];

            // 중복 제거
            ret -= contains_thirteen_cnt[num_string.size() - i - 1];
          }
        }
        ret += contains_thirteen_cnt[num_string.size() - i - 1];
      }
    }

    if (i && !contains_thirteen && num_string[i] == '3' && num_string[i - 1] == '1')
      contains_thirteen = true;
  }

  if (contains_thirteen)
    ret++;

  return ret;
}