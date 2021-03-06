// generated by derplanner [http://www.github.com/alexshafranov/derplanner]
#include "derplanner/runtime/domain.h"
#include "run_5.h"

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

static Compound_Task_Expand* s_task_expands[] = {
  r_case_0,
};

static const char* s_fact_names[] = {
  "a",
 };

static const char* s_task_names[] = {
  "p!",
  "r",
 };

static Fact_Type s_fact_types[] = {
  { 3, {Type_Int32, Type_Int32, Type_Int8, } },
};

static Type s_layout_types[] = {
  Type_Int32,
  Type_Int32,
};

static size_t s_layout_offsets[2];

static Param_Layout s_task_parameters[] = {
  { 2, 0, 0, s_layout_types + 0, s_layout_offsets + 0 },
  { 0, 0, 0, 0, 0 },
};

static Param_Layout s_bindings[] = {
  { 2, 0, 0, s_layout_types + 0, s_layout_offsets + 0 },
};

static uint32_t s_num_cases[] = {
  1, 
};

static uint32_t s_first_case[] = {
  0, 
};

static uint32_t s_size_hints[] = {
  0,
};

static uint32_t s_num_case_handles[] = {
  1, 
};

static uint32_t s_fact_name_hashes[] = {
  2456313694, 
};

static uint32_t s_task_name_hashes[] = {
  1274055463, 
  744399309, 
};

static const char* s_symbol_values[] = {
  0
 };

static uint32_t s_symbol_hashes[] = {
  0
};

static Domain_Info s_domain_info = {
  { 2, 1, 1, s_num_cases, s_first_case, 0, s_task_name_hashes, s_task_names, s_task_parameters, s_bindings, s_num_case_handles, s_task_expands },
  { 1, 0, s_size_hints, s_fact_types, s_fact_name_hashes, s_fact_names },
  { 0, 0, s_symbol_hashes, s_symbol_values }
};

void run_5_init_domain_info()
{
  for (size_t i = 0; i < plnnr_static_array_size(s_task_parameters); ++i) {
    compute_offsets_and_size(&s_task_parameters[i]);
  }

  for (size_t i = 0; i < plnnr_static_array_size(s_bindings); ++i) {
    compute_offsets_and_size(&s_bindings[i]);
  }
}

const Domain_Info* run_5_get_domain_info() { return &s_domain_info; }

struct S_1 {
  int32_t _0;
  int32_t _1;
};

static bool p0_next(Planning_State* state, Expansion_Frame* frame, Fact_Database* db)
{
  Fact_Handle* handles = frame->handles;
  S_1* binds = (S_1*)(frame->bindings);

  plnnr_coroutine_begin(frame, precond_label);

  for (handles[0] = first(db, tbl(state, 0)); is_valid(db, handles[0]); handles[0] = next(db, handles[0])) { // a
    binds->_0 = int32_t(as_Int32(db, handles[0], 0));
    binds->_1 = int32_t(as_Int32(db, handles[0], 1));
    if (binds->_1 != int32_t(as_Int8(db, handles[0], 2))) {
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
    binds = binds + frame->binding_index;
    begin_task(state, &s_domain_info, 0); // p!
    set_task_arg(state, &s_task_parameters[0], 0, int32_t(binds->_0));
    set_task_arg(state, &s_task_parameters[0], 1, int32_t(binds->_1));
    plnnr_coroutine_yield(frame, expand_label, 1);

    continue_iteration(state, frame);
  }

  if (frame->status == Expansion_Frame::Status_Was_Expanded) {
    frame->status = Expansion_Frame::Status_Expanded;
    plnnr_coroutine_yield(frame, expand_label, 2);
  }

  plnnr_coroutine_end();
}

