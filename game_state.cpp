#include "game_state.h"

game_state::game_state()
{
}

game_state::~game_state()
{
     for(auto& m : menu_stack)
     {
          for(auto& cmd : m->get_commands())
          {
               delete cmd;
               cmd = nullptr;
          }
          delete m;
          m = nullptr;
     }
     menu_stack.clear();
}
