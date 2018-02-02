/*
 * Copyright © 2018  Google, Inc.
 *
 *  This is part of HarfBuzz, a text shaping library.
 *
 * Permission is hereby granted, without written agreement and without
 * license or royalty fees, to use, copy, modify, and distribute this
 * software and its documentation for any purpose, provided that the
 * above copyright notice and the following two paragraphs appear in
 * all copies of this software.
 *
 * IN NO EVENT SHALL THE COPYRIGHT HOLDER BE LIABLE TO ANY PARTY FOR
 * DIRECT, INDIRECT, SPECIAL, INCIDENTAL, OR CONSEQUENTIAL DAMAGES
 * ARISING OUT OF THE USE OF THIS SOFTWARE AND ITS DOCUMENTATION, EVEN
 * IF THE COPYRIGHT HOLDER HAS BEEN ADVISED OF THE POSSIBILITY OF SUCH
 * DAMAGE.
 *
 * THE COPYRIGHT HOLDER SPECIFICALLY DISCLAIMS ANY WARRANTIES, INCLUDING,
 * BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND
 * FITNESS FOR A PARTICULAR PURPOSE.  THE SOFTWARE PROVIDED HEREUNDER IS
 * ON AN "AS IS" BASIS, AND THE COPYRIGHT HOLDER HAS NO OBLIGATION TO
 * PROVIDE MAINTENANCE, SUPPORT, UPDATES, ENHANCEMENTS, OR MODIFICATIONS.
 *
 * Google Author(s): Garret Rieger, Rod Sheeter
 */

#include "main-font-text.hh"

/*
 * Command line interface to the harfbuzz font subsetter.
 */

struct main_subset_t
{
  main_subset_t (void)
      : options ("--font-file <a font> --unicodes <codepoints to retain>"),
        subset_opts (&options) {}

  int
  main (int argc, char **argv)
  {
    options.parse (&argc, &argv);

    argc--, argv++;
    if (argc && !subset_opts.font_file) subset_opts.font_file = locale_to_utf8 (argv[0]), argc--, argv++;
    if (argc)
      fail (true, "Too many arguments on the command line");
    if (!subset_opts.font_file)
      options.usage ();

    // TODO do something useful :)

    //hb_buffer_t *buffer = hb_buffer_create ();
    //consumer.init (buffer, &font_opts);
    //hb_buffer_destroy (buffer);

    /*unsigned int text_len;
    const char *text;
    while ((text = input.get_line (&text_len)))
      consumer.consume_line (text, text_len, input.text_before, input.text_after);

    consumer.finish (&font_opts);*/

    //return consumer.failed ? 1 : 0;
    return 0;
  }

  protected:
  option_parser_t options;
  subset_options_t subset_opts;
};

int
main (int argc, char **argv)
{
  main_subset_t driver;
  return driver.main (argc, argv);
}
