<?php

	if ( !empty( $row->field_field_images_2 ) ) 
	{
		$img = $row->field_field_images_2[0]['raw'];
		$style = $field->options['settings']['image_style'];
		//$img_src_full = file_create_url( file_create_url( $img['uri'] ) );
		$img_src = image_style_url( $style, $img['uri'] );

		print( $img_src );
	}