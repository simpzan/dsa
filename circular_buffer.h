
#ifndef CIRCULAR_BUFFER_H_
#define CIRCULAR_BUFFER_H_

#include <stdbool.h>
#include <stdint.h>

typedef struct circular_buf_t* cbuf_handle_t;
cbuf_handle_t circular_buf_init(size_t size);
void circular_buf_free(cbuf_handle_t me);

/// Reset the circular buffer to empty, head == tail. Data not cleared
void circular_buf_reset(cbuf_handle_t me);

/// Put that continues to add data if the buffer is full
/// Old data is overwritten
/// Note: if you are using the threadsafe version, this API cannot be used, because
/// it modifies the tail pointer in some cases. Use circular_buf_try_put instead.
void circular_buf_put(cbuf_handle_t me, uint8_t data);

/// Put that rejects new data if the buffer is full
/// Note: if you are using the threadsafe version, *this* is the put you should use
/// Returns 0 on success, -1 if buffer is full
int circular_buf_try_put(cbuf_handle_t me, uint8_t data);

/// Retrieve a value from the buffer
/// Returns 0 on success, -1 if the buffer is empty
int circular_buf_get(cbuf_handle_t me, uint8_t* data);

/// CHecks if the buffer is empty
bool circular_buf_empty(cbuf_handle_t me);
/// Checks if the buffer is full
bool circular_buf_full(cbuf_handle_t me);
/// Check the current number of elements stored in the buffer
size_t circular_buf_size(cbuf_handle_t me);
/// Check the maximum capacity of the buffer
size_t circular_buf_capacity(cbuf_handle_t me);

/// Look ahead at values stored in the circular buffer without removing the data
/// Requires:
///		- me is valid and created by circular_buf_init
///		- look_ahead_counter is less than or equal to the value returned by circular_buf_size()
/// Returns 0 if successful, -1 if data is not available
int circular_buf_peek(cbuf_handle_t me, uint8_t* data, unsigned int look_ahead_counter);

#endif // CIRCULAR_BUFFER_H_