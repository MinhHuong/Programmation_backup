drop profile profile_all_users cascade;
drop profile profile_guichets cascade;

alter system set resource_limit = true;

create 	profile profile_all_users 
limit	failed_login_attempts 3;

create	profile profile_guichets
limit	SESSIONS_PER_USER 1
		FAILED_LOGIN_ATTEMPTS 3;