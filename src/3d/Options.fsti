module Options
open HashingOptions
open FStar.All

val display_usage : unit -> ML unit

val parse_cmd_line : unit -> ML (list string)

val get_file_name (mname:string) : ML string

val get_module_name (file: string) : ML string

val get_output_dir : unit -> ML string

val get_error_log : unit -> ML string

val get_error_log_function : unit -> ML string

val debug_print_string (s:string) : ML unit

val get_batch : unit -> ML bool

val get_clang_format : unit -> ML bool

val get_clang_format_executable : unit -> ML string

val get_cleanup : unit -> ML bool

val get_skip_makefiles : unit -> ML bool

val get_no_everparse_h : unit -> ML bool

val get_check_hashes : unit -> ML (option check_hashes_t)

val get_save_hashes : unit -> ML bool

val get_check_inplace_hashes : unit -> ML (list string)

val get_equate_types_list : unit -> ML (list (string & string))
