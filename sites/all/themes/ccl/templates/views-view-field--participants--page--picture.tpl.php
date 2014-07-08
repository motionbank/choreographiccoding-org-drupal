<?php
	$img_id = $row->users_picture;
	//$img_file = field_file_load( $img_id );
	if ( $img_id > 0 ) {
		$img = file_load( $img_id );
		$style = $field->options['image_style'];
		//$img_src_full = file_create_url( file_create_url( $img['uri'] ) );
		$img_src = image_style_url( $style, $img->uri );

		print $img_src;
	}