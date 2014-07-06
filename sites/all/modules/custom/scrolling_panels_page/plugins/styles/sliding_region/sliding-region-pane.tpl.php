<?php
	$bg_image_path = '';
	if ( !empty( $settings['background_image_file'] ) )
		$bg_image_path = $settings['background_image_file']['style_paths']['large']['path'];

?><div class="pane" style="background-image:url(<?php print $bg_image_path ?>) <?php 
		if ( property_exists($content,'css_class') ) print $content->css_class 
	?>" id="<?php if ( property_exists($content,'css_id') ) print $content->css_id ?>">
	<div class="inner">
		<?php if (isset($content->title)): ?>
			<h2 class="pane-title"><?php print $content->title; ?></h2>
		<?php endif ?>
		<div class="pane-content">
			<?php print render($content->content); ?>
		</div>
	</div>
</div>