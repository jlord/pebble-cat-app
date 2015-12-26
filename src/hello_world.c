#include <pebble.h>

Window *window;
TextLayer *text_layer;

static GBitmap *cat_bitmap;
static BitmapLayer *s_bitmap_layer;

void handle_init(void) {
  cat_bitmap = gbitmap_create_with_resource(RESOURCE_ID_CAT_PHOTO);
  
  s_bitmap_layer = bitmap_layer_create(GRect(0, 0, 180, 180));
  bitmap_layer_set_bitmap(s_bitmap_layer, cat_bitmap);

	// Create a window and text layer
	window = window_create();
  layer_add_child(window_get_root_layer(window), bitmap_layer_get_layer(s_bitmap_layer));

	// Push the window
	window_stack_push(window, true);
	
	// App Logging!
	APP_LOG(APP_LOG_LEVEL_DEBUG, "Just pushed a window!");
}

void handle_deinit(void) {  
  gbitmap_destroy(cat_bitmap);
  bitmap_layer_destroy(s_bitmap_layer);
	
	// Destroy the window
	window_destroy(window);
}

int main(void) {
	handle_init();
	app_event_loop();
	handle_deinit();
}
