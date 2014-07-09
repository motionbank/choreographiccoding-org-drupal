<div class="ratio"></div>
<div class="project" style="background-image: url(<?php print $fields['field_images_2']->content ?>)">
	<div class="content">
		<div class="title"><?php 
			$url = '';
			if ( !empty( $fields['field_url']->content ) ) {
				$url = $fields['field_url']->content;
			} else if ( !empty( $fields['field_source_url']->content ) ) {
				$url = $fields['field_source_url']->content;
			}
			if ( !empty( $url ) ) print l( $fields['title']->content, $url, array( 'attributes' => array( 'target' => '_blank' ) ) );
			else print $fields['title']->content;
		?></div>
		<div class="participants"><?php print $fields['view']->content ?></div>
	</div>
</div>