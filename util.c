/*
 * Copyright (c) 2017 Tobias Stoeckmann <tobias@stoeckmann.org>
 *
 * Permission to use, copy, modify, and distribute this software for any
 * purpose with or without fee is hereby granted, provided that the above
 * copyright notice and this permission notice appear in all copies.
 *
 * THE SOFTWARE IS PROVIDED "AS IS" AND THE AUTHOR DISCLAIMS ALL WARRANTIES
 * WITH REGARD TO THIS SOFTWARE INCLUDING ALL IMPLIED WARRANTIES OF
 * MERCHANTABILITY AND FITNESS. IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR
 * ANY SPECIAL, DIRECT, INDIRECT, OR CONSEQUENTIAL DAMAGES OR ANY DAMAGES
 * WHATSOEVER RESULTING FROM LOSS OF USE, DATA OR PROFITS, WHETHER IN AN
 * ACTION OF CONTRACT, NEGLIGENCE OR OTHER TORTIOUS ACTION, ARISING OUT OF
 * OR IN CONNECTION WITH THE USE OR PERFORMANCE OF THIS SOFTWARE.
 */

#include <err.h>
#include <stdint.h>
#include <stdlib.h>

size_t
safe_mul(size_t x, size_t y)
{
	if (x == 0 || y == 0)
		errx(1, "attempted to allocate 0 bytes");

	if (SIZE_MAX / x < y)
		errx(1, "memory allocation would exceed system limits");

	return x * y;
}

size_t
safe_mul3(size_t x, size_t y, size_t z)
{
	return safe_mul(x, safe_mul(y, z));
}

void *
xmalloc(size_t n)
{
	void *p;

	p = malloc(n);
	if (p == NULL)
		err(1, "failed to allocate memory");

	return p;
}
