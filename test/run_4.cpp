// generated by derplanner [http://www.github.com/alexshafranov/derplanner]
#include "derplanner/runtime/domain_support.h"
#include "run_4.h"

using namespace plnnr;

#ifdef __GNUC__
#pragma GCC diagnostic ignored "-Wunused-parameter"
#pragma GCC diagnostic ignored "-Wunused-variable"
#endif

#ifdef _MSC_VER
#pragma warning(disable: 4100) // unreferenced formal parameter
#pragma warning(disable: 4189) // local variable is initialized but not referenced
#endif

static bool r_case_0(Planning_State*, Expansion_Frame*, Fact_Database*);
static bool t_case_0(Planning_State*, Expansion_Frame*, Fact_Database*);

static Composite_Task_Expand* s_task_expands[] = {
  r_case_0,
  t_case_0,
};

static const char* s_fact_names[] = {
  "a",
  "b",
 };

static const char* s_task_names[] = {
  "p1!",
  "p2!",
  "r",
  "t",
 };

static Fact_Type s_fact_types[] = {
  { 1, {Type_Id32, } },
  { 1, {Type_Id32, } },
};

static Type s_layout_types[] = {
  Type_Id32,
};

static size_t s_layout_offsets[1];

static Param_Layout s_task_parameters[] = {
  { 1, s_layout_types + 0, 0, s_layout_offsets + 0 },
  { 1, s_layout_types + 0, 0, s_layout_offsets + 0 },
  { 0, 0, 0, 0 },
  { 1, s_layout_types + 0, 0, s_layout_offsets + 0 },
};

static Param_Layout s_bindings[] = {
  { 1, s_layout_types + 0, 0, s_layout_offsets + 0 },
  { 0, 0, 0, 0 },
};

static uint32_t s_num_cases[] = {
  1, 
  1, 
};

static uint32_t s_first_case[] = {
  0, 
  1, 
};

static uint32_t s_size_hints[] = {
  0, 
  0, 
};

static uint32_t s_num_case_handles[] = {
  1, 
  1, 
};

static uint32_t s_fact_name_hashes[] = {
  2456313694, 
  2260187636, 
};

static uint32_t s_task_name_hashes[] = {
  3160289330, 
  3193124031, 
  744399309, 
  2418444476, 
};

static Domain_Info s_domain_info = {
  { 4, 2, 2, s_num_cases, s_first_case, 0, s_task_name_hashes, s_task_names, s_task_parameters, s_bindings, s_num_case_handles, s_task_expands },
  { 2, 0, s_size_hints, s_fact_types, s_fact_name_hashes, s_fact_names },
};

void run_4_init_domain_info()
{
  for (size_t i = 0; i < plnnr_static_array_size(s_task_parameters); ++i) {
    compute_offsets_and_size(s_task_parameters[i]);
  }

  for (size_t i = 0; i < plnnr_static_array_size(s_bindings); ++i) {
    compute_offsets_and_size(s_bindings[i]);
  }
}

const Domain_Info* run_4_get_domain_info() { return &s_domain_info; }

struct S_1 {
  Id32 _0;
};

static bool p0_next(Planning_State* state, Expansion_Frame* frame, Fact_Database* db)
{
  Fact_Handle* handles = frame->handles;
  S_1* binds = (S_1*)(frame->bindings);

  plnnr_coroutine_begin(frame, precond_label);

  for (handles[0] = first(db, 0); is_valid(db, handles[0]); handles[0] = next(db, handles[0])) { // a
    binds->_0 = Id32(as_Id32(db, handles[0], 0));
    plnnr_coroutine_yield(frame, precond_label, 1);
  }

  plnnr_coroutine_end();
}

static bool p1_next(Planning_State* state, Expansion_Frame* frame, Fact_Database* db, const S_1* args)
{
  Fact_Handle* handles = frame->handles;

  plnnr_coroutine_begin(frame, precond_label);

  for (handles[0] = first(db, 1); is_valid(db, handles[0]); handles[0] = next(db, handles[0])) { // b
    if (args->_0 != Id32(as_Id32(db, handles[0], 0))) {
      continue;
    }

    plnnr_coroutine_yield(frame, precond_label, 1);
  }

  plnnr_coroutine_end();
}

static bool r_case_0(Planning_State* state, Expansion_Frame* frame, Fact_Database* db)
{
  const S_1* binds = (const S_1*)(frame->bindings);

  plnnr_coroutine_begin(frame, expand_label);

  while (p0_next(state, frame, db)) {
    begin_task(state, &s_domain_info, 0); // p1!
    set_task_arg(state, s_task_parameters[0], 0, binds->_0);
    plnnr_coroutine_yield(frame, expand_label, 1);

    begin_composite(state, &s_domain_info, 3); // t
    set_composite_arg(state, s_task_parameters[3], 0, binds->_0);
    plnnr_coroutine_yield(frame, expand_label, 2);

    continue_iteration(state, frame);
  }

  if (frame->status == Expansion_Frame::Status_Was_Expanded) {
    frame->status = Expansion_Frame::Status_Expanded;
    plnnr_coroutine_yield(frame, expand_label, 3);
  }

  plnnr_coroutine_end();
}

static bool t_case_0(Planning_State* state, Expansion_Frame* frame, Fact_Database* db)
{
  const S_1* args = (const S_1*)(frame->arguments);

  plnnr_coroutine_begin(frame, expand_label);

  while (p1_next(state, frame, db, args)) {
    begin_task(state, &s_domain_info, 1); // p2!
    set_task_arg(state, s_task_parameters[1], 0, args->_0);
    frame->status = Expansion_Frame::Status_Expanded;
    plnnr_coroutine_yield(frame, expand_label, 1);

  }

  plnnr_coroutine_end();
}

