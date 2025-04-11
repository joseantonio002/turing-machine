#include "tape.h"

tape::tape(string entrada)
{
    current_pos = 0;
    if (entrada != " ")
    {
        for (char c : entrada)
        {
            positive_tape.push_back(string(1, c));
        }
    }
    else
    {
        positive_tape.push_back(BLANK);
    }
    negative_tape.push_back(BLANK);
}

string tape::read_tape()
{
  if (current_pos >= int(positive_tape.size()) || current_pos < -int(negative_tape.size()))
  {
    return BLANK;
  }
  if (current_pos >= 0)
  {
    return positive_tape[current_pos];
  }
  else
  {
    return negative_tape[-current_pos - 1]; // la posición 0 es de la positive tape, por eso le resta 1
  }
}

void tape::execute_action(simbol_movement sm)
{
  if (sm.movement == STOP)
  {
    return;
  }
  if (current_pos >= 0)
  {
    if (current_pos >= positive_tape.size())
    {
      positive_tape.push_back(sm.simbol);
    }
      positive_tape[current_pos] = sm.simbol;
  }
  else
  {
      if (current_pos < -negative_tape.size())
      {
        negative_tape.push_back(sm.simbol);
      }
      negative_tape[-current_pos - 1] = sm.simbol;
  }
  if (sm.movement == LEFT)
    current_pos--; 
  else if (sm.movement == RIGHT)
    current_pos++;
}

void tape::show_tape()
{
    //cout << "current_pos: " << current_pos << endl;
    //cout << "negative_tape: " << negative_tape.size() << endl;
    //cout << "positive_tape: " << positive_tape.size() << endl;
    if (-current_pos - 1 >= int(negative_tape.size()))
    {
      //cout << "(.) ";
    }
    for (int i = negative_tape.size() - 1; i >= 0; i--)
    {
        if (i == -current_pos - 1)
        {
            cout << "(" << negative_tape[i] << ") ";
        }
        else
        {
            cout << negative_tape[i] << " ";
        }
    }
    for (int i = 0; i < positive_tape.size(); i++)
    {
        if (i == current_pos)
        {
            cout << "(" << positive_tape[i] << ") ";
        }
        else
        {
            cout << positive_tape[i] << " ";
        }
    }
    if (current_pos >= int(positive_tape.size()))
    {
      //cout << "(.)";
    }
    cout << endl;
}